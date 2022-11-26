/*
*   Copyright 2022 Kaz Voeten
*
*	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterComponents/IKBodyComponent.h"
#include "Library/AnimationStructLibrary.h"

#include "IKCharacterAnimInstance.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogIKBodyAnimation, Log, All);

class IKBodyComponent;

/**
 * Main anim instance class for character
 */
UCLASS(Blueprintable, BlueprintType)
class UNREALBODY_API UIKCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	/** Constructor to set up Pawn and Character */
	virtual void NativeInitializeAnimation() override;

	/**
	*	Update Character IKBody component
	* Make a call to update each IK Value
	*/
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	/** 
	* Update Foot IK
	*	Get sockets for left and Right foot
	* Trace each foot based on world location
	*/
	void UpdateFootIK();

	/**
	* Update movement values to be passed to Blendspace
	* Values include speed and direction
	*/
	void UpdateMovementValues();

	/**
	* Update head values based on Pawn camera
	* Values include Rotation and Location
	*/
	void UpdateHeadValues();

	/**
	* Update hand values by tracking each controller
	* Apply transforms to each respective socket and parent bone space for IK
	*/
	void UpdateHandValues();

	void UpdateFingerIKValues();

	/** Helper function that performs foot trace and sets Anim Graph values */
	void TraceFoot(FVector Foot, FVector* ResultLocation,
		FRotator* ResultRotation, UWorld* World, FCollisionQueryParams* Params);

protected:
	/** Reference to IKBody component */
	UPROPERTY(BlueprintReadOnly, Category = "Default")
	UIKBodyComponent* BodyComponent = nullptr;

	/** Reference to Pawn */
	UPROPERTY(BlueprintReadOnly, Category = "Default")
	APawn* Character = nullptr;

protected:
	/** Anim Graph - Movement */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Movement", Meta = (
		ShowOnlyInnerProperties))
	FAnimGraphMovement MovementValues;

	/** Anim Graph - Foot IK */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Head IK", Meta = (
		ShowOnlyInnerProperties))
	FAnimGraphHeadIK HeadIKValues;

	/** Anim Graph - Foot IK */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Foot IK", Meta = (
		ShowOnlyInnerProperties))
	FAnimGraphFootIK FootIKValues;

	/** Anim Graph - Context Awareness */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Arm IK", Meta = (
		ShowOnlyInnerProperties))
	FAnimGraphArmIK ArmIKValues;

		/** Anim Graph - Context Awareness */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Read Only Data|Anim Graph - Finger IK", Meta = (
		ShowOnlyInnerProperties))
	FAnimGraphFingerIK FingerIKValues;
};
