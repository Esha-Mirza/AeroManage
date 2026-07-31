#include <iostream>

#include "Admin.h"
using namespace std;


#include "Passenger.h"
#include "Booking.h"
#include "Seat.h"
#include "Tickets.h"
#include "Payment.h"
#include "CarryLuggage.h"
#include "ReviewSystem.h"
#include "Flight.h"
#include "LoyaltyProgram.h"

int main() {
	int mainChoice;

	do {
		cout << "\n--- Welcome to MEH Ticket Reservation System ---\n";
		cout << "1. Admin\n";
		cout << "2. Passenger\n";
		cout << "3. Exit Program\n"<<endl;
		cout << "Enter your choice: ";
		cin >> mainChoice;
		cin.ignore(10000, '\n');

		if (mainChoice == 1) {
			Admin admin;
			int adminOption;
			do {
				cout << "\n--- Admin Menu ---\n";
				cout << "1. Register Admin\n";
				cout << "2. Login Admin\n";
				cout << "3. Back to Main Menu\n"<<endl;
				cout << "Enter your option: ";
				cin >> adminOption;
				cin.ignore(10000, '\n');

				if (adminOption == 1) {
					admin.registerUser();
				} else if (adminOption == 2) {
					admin.login();
					int adminTask;
					do {
						cout << "\n--- Admin Task Menu ---\n";
						cout << "1. Mark attendance\n";
						cout << "2. Add Flight\n";
						cout << "3. Back to Admin Menu\n"<<endl;
						cout << "Enter task number: ";
						cin >> adminTask;
						cin.ignore(10000, '\n');

						switch (adminTask) {
						case 1:
							admin.markAttendance();
							break;
						case 2:
							admin.addFlight();
							break;
						case 3:
							cout << "Returning to Admin Menu...\n";
							break;
						default:
							cout << "Invalid choice.\n";
						}
					} while (adminTask != 3);
				}
			} while (adminOption != 3);
		}

		else if (mainChoice == 2) {
			Passenger passenger;
			int passOption;
			ReviewSystem reviewSystem;

			do {
				cout << "\n--- Passenger Menu ---\n";
				cout << "1. Register Passenger\n";
				cout << "2. Login Passenger\n";
				cout << "3. Back to Main Menu\n"<<endl;
				cout << "Enter your option: ";
				cin >> passOption;
				cin.ignore(10000, '\n');


				if (passOption == 1) {
					passenger.registerUser();
				} else if (passOption == 2) {
					passenger.login();

					Booking booking;
					Payment payment;
					MealSelection meal;
					Seat seat;
					Tickets ticket;
					LoyaltyProgram loyalty;
					CarryLuggage luggage;

					int task;
					do {
						cout << "\n--- Passenger Task Menu ---\n";
						cout << "1. Carry Luggage\n";
						cout << "2. Meal Selection\n";
						cout << "3. Book/Cancel Ticket\n";
						cout << "4. Leave Review\n";
						cout << "5. View Boarding Pass\n";
						cout << "6. loyalty program\n";
						cout << "7. Back to Passenger menu\n"<<endl;
						cout << "Enter your choice: ";
						cin >> task;

						switch (task) {
						case 1:
							luggage.chargeFee(&payment);
							payment.receivePayment();
							break;
						case 2:
							meal.selectType();
							break;
						case 3: {
							int bookingOption;
							cout <<"... What would you like to do?...\n";
							cout << "1. Start Booking\n";
							cout << "2. Cancel Booking\n"<<endl;
							cout << "Enter booking option: ";
							cin >> bookingOption;

							if (bookingOption == 1) {
								Flight flight;

								cout << "\n...Available Flights...\n";
								flight.displayFlights();
								string chosenFlightID;
								cout <<"//////////////////////////////////////////////////////////////\n";

								cout << "Enter Flight ID you want to book: ";
								cin >> chosenFlightID;

								if (flight.isValidFlightID(chosenFlightID)) {
									cout << "Flight ID valid! Proceeding with booking...\n"<<endl;

									booking.startBooking(passenger, payment, seat, ticket, meal, loyalty, luggage);

								} else {
									cout << "Invalid Flight ID entered. Please try again.\n";
								}

							} else if (bookingOption == 2) {
								booking.cancelBooking(passenger);

							} else {
								cout << "Invalid booking option.\n";
							}
							break;
						}
						case 4:
							reviewSystem.leaveReview();
							break;
						case 5:
							ticket.displayTicket(&passenger);
							break;

						case 7:
							cout << "Returning to Passenger Menu...\n";
							break;

						case 6:

							loyalty.showLoyaltyStatus(passenger);
							break;
						default:
							cout << "Invalid task choice.\n";
						}
					} while (task != 7);
				}
			} while (passOption != 3);
		}

		else if (mainChoice == 3) {
			cout << "Exiting program...\n";
		} else {
			cout << "Invalid main menu choice.\n";
		}

	} while (mainChoice != 3);

	return 0;
}
