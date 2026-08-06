#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137),
      target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137),
      target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm& other)
    : AForm(other),
      target(other.target);
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);

    return *this;
}

ShrubberyCerationFrom::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(
    const Bureaucrat& executor) const
{
    checkExecution(executor);

    std::ofstream file((target + "_shrubbery").c_str());

    if (!file)
        throw std::runtime_error("could not create shrubbery file");

    file << "       /\\\n"
         << "      /**\\\n"
         << "     /****\\\n"
         << "    /******\\\n"
         << "   /********\\\n"
         << "       ||\n"
         << "       ||\n";
}