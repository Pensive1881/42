#include "Beaurocrat.hpp"

Bureaucrat::Bureaucrat()
    : name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{

}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{

}

int Bureaucrat::getGrade() const
{

}

void Bureaucrat::incrementGrade()
{

}

void Bureaucrat::decrementGrader()
{

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{

}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{

}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat)
{
    
}