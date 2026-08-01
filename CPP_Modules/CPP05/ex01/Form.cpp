#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("Default"),
      isSigned(false),
      gradeToSign(150),
      gradeToExecute(150)
{
}

Form::Form(const std::string& name,
           int gradeToSign,
           int GradeToExecute)
    : name(name),
      isSigned(false),
      gradeToSign(gradeToSign),
      GradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();

    if (gradeToSign > 150 || gradeToExecute > 150)
        throw();
}

Form::Form(const Form& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{
}

Form& Form::operator=()
{
    if (this != &other)
        isSigned = other.isSigned;
    
    return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form:getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw (bureaucrat.getGrade() > gradeToSign)
    
        isSigned = true;
}

const chat* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

std::ostream& operator<<()
{
    output << form.getName()
           << ", signed: "
           << (form.getIsSigned() ? "yes" : "no")
           << ", grade required to sign: "
           << form.getGradeToSign()
           << ", grade required to execute: "
           << form.getGradeToExecute()
           << ".";

    return output;
}