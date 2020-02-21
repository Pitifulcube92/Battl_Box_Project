// Fill out your copyright notice in the Description page of Project Settings.


#include "Equation.h"
#include "Debugger.h"
#include "../Battle_Box/Private/ActionClasses/BaseAction.h"
#include "../Battle_Box/Private/ActionClasses/ItemAction.h"
#include "../Battle_Box/Private/ActionClasses/AbilityAction.h"
Equation::Equation()
{
generalScalar = 2.0f;
rise = 1.0f;
run = 2.0f;
xIntercept = 3.0f;
equationType = EQUATION_TYPE::E_NONE;
}

Equation::Equation(float scalar_, float rise_, float run_, float xIntercept_, EQUATION_TYPE equationType_)
{
	generalScalar = scalar_;
	rise = rise_;
	run = run_;
	xIntercept = xIntercept_;
	equationType = equationType_;
}
Equation::Equation(Equation& const other_)
{
	generalScalar = other_.ReturnGenrealScale();
	rise = other_.ReturnRise();
	run = other_.ReturnRun();
	xIntercept = other_.ReturnXIntercept();
}
Equation::~Equation()
{
}
float Equation::ReturnGenrealScale() const
{
	return generalScalar;
}
float Equation::ReturnRise() const
{
	return rise;
}
float Equation::ReturnRun() const
{
	return run;
}
float Equation::ReturnXIntercept() const
{
	return xIntercept;
}
float Equation::DetermineEquation(float input_)
{
	float foo; // foo is the final number from each equation
	switch (equationType)
	{
	case EQUATION_TYPE::E_EXPONENT:
		foo = Exponential(input_);
		return foo;
	case EQUATION_TYPE::E_LINEAR:
		foo = Linear(input_);
		return foo;
	case EQUATION_TYPE::E_QUADRADIC:
		foo = Quadratic(input_);
		return foo;
	case EQUATION_TYPE::E_DIV:
		foo = Div(input_);
		return foo;
	case EQUATION_TYPE::E_SINE:
		foo = Sine(input_);
		return foo;
	case EQUATION_TYPE::E_COSINE:
		foo = Cosine(input_);
		return foo;
	case EQUATION_TYPE::E_NONE:
		return 0.0f;
	default:
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Equation type not valid", "Equation.cpp", __LINE__);
		break;
	}
	return 0.0f;
}

float Equation::Exponential(float input_) // exponential function
{
	//x is the constant
	//fx = ab^x 
	if (input_ == 0.0f) {
		Debugger::SetSeverity(MessageType::E_WARNING);
		Debugger::Warrning("Input is 0", "Equation.cpp", __LINE__);
	}
	float f = FMath::Pow(generalScalar, input_) + rise;
	return f;
}

float Equation::Div(float input_)
{
	if (input_ == 0.0f) {
		Debugger::SetSeverity(MessageType::E_WARNING);
		Debugger::Warrning("Input is 0", "Equation.cpp", __LINE__);
	}
	float f = input_ / 2;

	return f;
}
EQUATION_TYPE Equation::RetrunEquationType() const
{
	return equationType;
}
float Equation::Sine(float input_)
{
	float f = FMath::Sin(input_);
	return f;
}

float Equation::Cosine(float input_)
{
	float f = FMath::Cos(input_);
	return f;
}

float Equation::Linear(float input_)
{
	float f = run * input_ + (rise);
	return f;
}

float Equation::Quadratic(float input_)
{
	// y = x^2 + x*b + c;
	float y = FMath::Pow(input_, 2.0f);  + (xIntercept * input_) + rise;
	return y;
}

float Equation::GetDamageMultiplier() const
{
	return damageMultipier;
}

void Equation::SetDamageMultiplier(float x_)
{
	damageMultipier = x_;
}

float Equation::GetDamageReducer() const
{
	return damageReducer;
}

void Equation::SetDamageReducer(float x_)
{
	damageReducer = x_;
}