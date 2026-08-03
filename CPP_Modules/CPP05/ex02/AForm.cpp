#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default"),
      isSigned(False),
      gradeToSign(150),
      gradeToExecute(150)
{
}

AForm::AForm(const std::string& name,
             int gradeToSign,
             int gradeToExecute)
    : name(name),
      isSigned(false),
      gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();

    if (GradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{

}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned( const Bureaucrat& bureaucrat)
{

}

void AForm::checkExecution(const Bureaucrat& executor) const
{

}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm is not signed";
}

std::ostream& operator<<(std::ostream& output, const AForm& form)
{

}