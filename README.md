🚗💰 C++ Car Rental & Bank Management System

A simple terminal-based Car Rental and Bank Management system written in C++. The app provides two core services:

    A Car Rental System for managing rentals, customer data, and car availability.

    A Banking System to create accounts, manage balances, transfer money, and more.

This project demonstrates strong use of object-oriented programming, modular design, file handling, password hashing using libsodium, and Makefile for build automation.
📁 Project Structure

    .
    ├── main.cpp               # Main entry point
    ├── banksystem.h/.cpp      # Banking system logic
    ├── System.h/.cpp          # Car rental system logic
    ├── helper.h               # Helper for config parsing and password hashing
    ├── config.ini             # Configuration file (not included in this repo by default)
    ├── Makefile               # Compilation instructions

Features
Bank Management System

    Create new bank accounts

    Deposit funds

    Transfer money between users

    Show balance

    Change user password (hashed with libsodium)

Car Rental System

    Register as a new customer

    View available cars

    Rent and return cars

    Pay using linked bank account

    View profile and payment status

Shared

    Command-line user interface with colored output

    Input validation and error handling

    Modular and maintainable code

🛠️ Installation
📦 Dependencies

You need the following libraries installed:

    g++ (C++11+)

    libsodium

    MariaDB Connector/C++ (optional, if you're integrating DB)

On Debian-based systems:

    sudo apt update
    sudo apt install g++ libsodium-dev libmariadb-dev libmariadbcpp-dev

🔧 Build

Use the provided Makefile to compile:

    make main        # Compiles main.cpp to 'main'

You can also compile manually:

    g++ -std=c++11 main.cpp System.cpp banksystem.cpp -o main -lsodium -lmariadbcpp -lmariadb

🧹 Clean build files

    make clean

🚀 Run the App

    ./main

You'll be prompted to choose between:

    1. Car Rental Service

    2. Banking Service

    3. Close the app

Each system then provides its own menu.
🔐 Security

    Passwords are hashed securely using libsodium (crypto_pwhash_str)

    Password validation uses crypto_pwhash_str_verify

    Config files are parsed from .ini format

📝 Configuration

If using a config file (like for storing DB settings or system info), create a config.ini file:

    [database]
    user = youruser
    password = yourpass
    host = localhost

Use loadIniConfig("config.ini") to read it.

Password Hashing

std::string hashPassword(const std::string& password);
bool validatePassword(const std::string hashed, std::string epassword);

👤 Author

    GitHub: admarspia

    Language: C++

    Operating System: Linux (tested on Kali)

📄 License

This project is for educational purposes. You are free to use, modify, and distribute it. Add your preferred open-source license if needed.
