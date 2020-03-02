// Fill out your copyright notice in the Description page of Project Settings.

#ifndef EQUATIONS_H		
#define EQUATIONS_H
#include "CoreMinimal.h"
#include "Math/UnrealMathUtility.h"
class BaseAction;
class Debugger;

class AbilityAction;
class ItemAction;
enum class EQUATION_MOD_TYPE {
	E_NULL = 1,
	E_ATTRIBUTE
};

enum class EQUATION_TYPE {
	E_NONE = 1,
	E_EXPONENT, 
	E_DIV,
	E_SINE,
	E_COSINE, 
	E_LINEAR,
	E_QUADRADIC
};
class BATTLE_BOX_API Equation
{
public:
	Equation();
	Equation(float scalar_, float rise_, float run_, float xIntercept_, EQUATION_TYPE equationType_);
	Equation(const Equation& other_);
	~Equation();
	float DetermineEquation(float input_);

	float GetDamageMultiplier() const;
	void SetDamageMultiplier(float x_);
	float GetDamageReducer() const;
	void SetDamageReducer(float x_);
	
	EQUATION_TYPE RetrunEquationType() const;
	float ReturnGenrealScale() const;
	float ReturnRise() const;
	float ReturnRun() const;
	float ReturnXIntercept() const;
private:
	float damageMultipier = 1.5f;
	float damageReducer = 1.5f;
	float generalScalar, rise, run, xIntercept;

	//f(x) = a^x + b
	float Exponential(float input_);
	// x/y
	float Div(float input_);
	// Sin(x)
	float Sine(float input_);
	// Cos(x)
	float Cosine(float input_);
	// y = f(x) = a + bx
	float Linear(float input_);
	// fx = x^2 + bx + c;
	float Quadratic(float input_);

	EQUATION_TYPE equationType;
	
	
	
};

#endif 