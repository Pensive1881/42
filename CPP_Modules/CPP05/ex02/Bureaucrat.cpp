#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
    : name("Default"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        grade = other.grade;

    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    
    --grade;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();

    ++grade;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);

        std::cout << name << " signed "
                  << form.getName() << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << name << " couldn't sign "
                  << form.getName()
                  << " because " << exception.what()
                  << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low";
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat)
{
    output << bureaucrat.getName()
           << ", bureaucrat grade "
           << bureaucrat.getGrade()
           << ".";

    return output;
}