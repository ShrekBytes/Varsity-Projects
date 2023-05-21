# Hospital Management

This hospital management application aims to simplify patient information management with an innovative and user-friendly interface, streamlining hospital processes for better efficiency.

## Features
- Login screen with username and password validation.
- Main menu with options to view all patients, add a new patient, and search for a specific patient.
- Add new patients to the system, including information such as name, age, gender, blood group, and contact details.
- Display a list of all patients with their respective patient numbers.
- Search for a patient by their name using fuzzy search, which allows for approximate matching.
- Each patient has a unique patient number assigned to them.
- Patient information includes their name, age, gender, blood group, contact details, emergency contact information, current physician, and date of admission.

## Getting Started
To run the application, follow these steps:

1. Clone the repository: `git clone <repository-url>`
2. Compile the source code: `gcc hospital_management.c -o hospital_management`
3. Run the executable: `./hospital_management`

## Usage
1. Launch the application and enter your username and password to log in.
<img src="/screenshots/login.png" alt="Varsity-Projects Logo" width="400" height="400">

2. Once logged in, you will be presented with the main menu.
3. Choose the desired option from the menu:
   - Option 1: View all patients.
   - Option 2: Add a new patient.
   - Option 3: Search for a patient.
   - Option 0: Log out.
4. If you choose to view all patients, a list of patients with their respective patient numbers will be displayed.
5. If you choose to add a new patient, enter the patient's information as prompted.
6. If you choose to search for a patient, enter the patient's name. The application will perform a fuzzy search and display the matching results.
7. To log out, select option 0 from the main menu.

## Dependencies
- The application requires a C compiler to compile and run the source code.
- The code has been tested on both Windows and Linux systems.

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.
