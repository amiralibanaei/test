#!/bin/sh

echo 'Please enter the user name:'
read -p "Username: " user
echo 'Please enter your password:'
read -p "Password: " pass

while [ $user != 'APNew' ] || [ $pass != 'APNew' ] ; do
      echo 'The username or password is incorrect'
      read -p "Username: " user
      read -p "Password: " pass
done

echo '\nWelcome, What do you want to do?'
echo 'Press 1 to make hello.cpp or press 2 to close terminal'
read code

if [ $code -eq '1' ] ; then
    mkdir -p AP2018
    cd AP2018
    echo | tee hello.cpp
    kill -9 $PPID
fi

if [ $code -eq '2' ] ; then
    kill -9 $PPID
fi
