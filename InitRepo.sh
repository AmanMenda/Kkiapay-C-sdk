#!/bin/bash

if [ $# -ne 1 ]; then
    echo -e $'Invalid operation:\n\e[4mUsage\e[0m: ./InitRepo.sh <destination_folder>'
    exit 0
fi

#Global variables
CURRENT_USER=$USER
LIB="/home/$CURRENT_USER/Epitech-lib"
UNIT_TEST_LIB_PATH="/home/$CURRENT_USER/tests"
DESTINATION_PATH=$1

cp $LIB $1 -r

#Makefile path
M_PATH=$1/Makefile

#Creer le fichier Makefile
touch Makefile

read -p "$(tput bold)Do you want to import your unit test folder (should be located at /Home/User) ? [Y/n]$(tput sgr0) " VALIDATION
read -p "$(tput bold)Binary name: $(tput sgr0)" BINARY_NAME

Header() {
    echo $'Loading Epitech header...'
    echo $'##' >> $M_PATH
    echo $'## EPITECH PROJECT, 2022' >> $M_PATH
    echo $'## Makefile C' >> $M_PATH
    echo $'## File description:' >> $M_PATH
    echo $'## GNUmakefile' >> $M_PATH
    echo $'##' >> $M_PATH
}

Variables() {
    echo $'Creating common variables...'
    echo -ne $'\nSRC\t=\t$(shell find . -type f -name "*.c")\n\n' >> $M_PATH
    if [ "$VALIDATION" == "y" ] || [ "$VALIDATION" == "Y" ] || [ -z "$VALIDATION" ]; then
        echo -ne $'Importing lib and creating unit test rule...\n'
        cp $UNIT_TEST_LIB_PATH $DESTINATION_PATH -r
        echo -ne $'TEST_SRC\t=\t$(shell find . -type f -name "tests/tests_*")\n\n' >> $M_PATH
    fi
    echo -ne $'OBJ\t=\t$(SRC:.c=.o)\n\n' >> $M_PATH
    echo $'Retrieve binary name...'
    sleep 1
    echo -ne "NAME\t=\t$BINARY_NAME\n\n" >> $M_PATH
}

commonRules() {
    echo -ne $'all:\t$(NAME)\n\n' >> $M_PATH

    #valgrind compilation:
    echo -ne $'%.o:\t%.c\n\tgcc -c $< -o $@ -g3\n\n' >> $M_PATH

    echo -ne $'$(NAME):\t$(OBJ)\n\tgcc -o $(NAME) $(OBJ) -g3\n\n' >> $M_PATH

    #clean rule:
    echo -ne $'clean:\n\t-rm -f $(OBJ)\n\n' >> $M_PATH

    #fclean rule:
    echo -ne $'fclean:\tclean\n\t-rm -f $(NAME)\n\t-rm -f *~\n\t-rm -f *#\n\t-rm -f vgcore.*\n\n' >> $M_PATH

    #re rule:
    echo -ne $'re:\tfclean all\n\n' >> $M_PATH
}

addUnitTestRule() {
    echo $'Adding unit test rule...'
    echo -ne $'tests_run:\t$(TEST_SRC)\n\tgcc -o $(TEST_NAME) $(TEST_SRC) --coverage -lcriterion\n' >> $M_PATH
    echo -ne $'\t./$(TEST_NAME)\n' >> $M_PATH
    echo -ne $'\tgcovr --exclude tests/\n' >> $M_PATH
    echo -ne $'\tgcovr --exclude tests/ --branches\n\n' >> $M_PATH
}

createGitIgnore() {
    touch .gitignore
    #Si path n'est pas "./", prendre en compte le path avec le mv
    local GIT_IGNORE_FILE_PATH=$DESTINATION_PATH/.gitignore

    echo $'#Scripts' >> $GIT_IGNORE_FILE_PATH
    echo $'InitRepo.sh/' >> $GIT_IGNORE_FILE_PATH
    echo $'TheDeliverer.sh/\n' >> $GIT_IGNORE_FILE_PATH
    echo $'#vscode folder' >> $GIT_IGNORE_FILE_PATH
    echo $'.vscode/*' >> $GIT_IGNORE_FILE_PATH
    echo $'gitignore added...'
}

function makefileGenesis() {
    Header
    Variables
    commonRules
    if [ "$VALIDATION" == "y" ] || [ "$VALIDATION" == "Y" ] || [ -z "$VALIDATION" ]; then
        addUnitTestRule
    fi
    echo -ne $'.PHONY:\tclean fclean all re' >> $M_PATH
    echo $'Makefile created...'
}

function main() {
    makefileGenesis
    createGitIgnore
}

main