#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class Food_menu {
private:
                // Data members
	int item_No;             
	int    item_price;
	int    drink_No;
	int    drink_price;
	int    Quantity;
	int    Quantity_drink;
	int    Total_price;
	int    pay_price;

public:
	Food_menu() {
                 //CREATING CONSTRUCTOR
		item_No = 0;
		item_price = 0;
		drink_No = 0;
		drink_price = 0;
		Quantity = 0;
		Total_price = 0;
		pay_price = 0;
		Quantity_drink = 0;

	}

	~Food_menu() {};       // Using the destructor

	void Display() {               // creating the display of the menu 
		cout << "----------------------------------------------------" << endl;
		cout << "------------------------MENU----------------------- " << endl;
		cout << "---------------------------------------------------" << endl;
		cout << setw(30) << "Food Section" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Food No" << setw(15) << "Food Name" << setw(25) << "Food Price" << endl;
		cout << "1" << setw(22) << " Chicken Burger" << setw(20) << "200" << endl;
		cout << "2" << setw(22) << "Sandwich" << setw(20) << "100" << endl;
		cout << "3" << setw(22) << "Shawarma" << setw(20) << "120" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << setw(30) << "Drink Section " << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Drink No" << setw(20) << "Drink Name" << setw(22) << "Drink Price " << endl;
		cout << "1" << setw(22) << "Coke" << setw(20) << "80" << endl;
		cout << "2" << setw(22) << "7-UP" << setw(20) << "80" << endl;
		cout << "3" << setw(22) << "FANTA" << setw(20) << "80" << endl;
		cout << "---------------------------------------------------" << endl;
	}

	void Set_itemNo(int IN) {
		item_No = IN;               // creating the Setters and the Getters of the data members
	}

	void Setitem_price(int IP) {
		item_price = IP;
	}
	void SetDrink_No(int DN) {
		drink_No = DN;
	}

	void Set_Quantity(int Q) {
		Quantity = Q;
	}

	void Set_Drink_Quantity(int DQ) {
		Quantity_drink = DQ;
	}

	void Set_Payprice(int PP) {
		pay_price = PP;
	}

	int Get_itemNo() {
		return item_No;   // Creating the Getters of the data members
	}

	int Get_itemPrice() {
		return item_price;
	}
	int Get_DrinkNo() {
		return drink_No;
	}

	int Get_DrinkPrice() {
		return drink_price;
	}
	int Get_Quantity() {
		return Quantity;
	}

	int Get_PayPrice() {
		return pay_price;
	}

	int Get_drink_Quantity() {
		return Quantity_drink;
	}

	int Price_of_item1() {
		int price_of_item;

		price_of_item = 200 * Quantity;
		return price_of_item;
	}

	int Price_of_item2() {
		int price_of_item;

		price_of_item = 100 * Quantity;
		return price_of_item;
	}

	int Price_of_item3() {
		int price_of_item;

		price_of_item = 120 * Quantity;
		return price_of_item;
	}

	int Price_of_drink(int Quantity_drink) {
		int price_of_drink;

		price_of_drink = 80 * Quantity_drink;
		return price_of_drink;
	}

	int Total_Price1() {               // CREATING THE ADDITION FUNCTIONS FOR TOTAL PRICE                                           
		Total_price = Price_of_drink(Quantity_drink) + Price_of_item1();
		return Total_price;
	}
	int Total_Price2() {
		Total_price = Price_of_drink(Quantity_drink) + Price_of_item2();
		return Total_price;
	}
	int Total_Price3() {
		Total_price = Price_of_drink(Quantity_drink) + Price_of_item3();
		return Total_price;
	}

	int Amount_Change(int Total_price, int pay_price) {
		int Change;
		Change = pay_price - Total_price;     //CREATING THE FUNCTION FOR CHANGE
		return Change;
	}
	int Order_Number() {
		static int i = 100;   //CREATING THE ORDER NO FUNCTION
		return ++i;
	}

	int Serial_No() {
		int Rand;
		Rand = rand() * rand() * rand();  // CREATING THE SERIAL NO FUNCTION
		return Rand / 10;
	}
	void Time() {
		time_t tt;
		struct tm* ti;    // CREATINGT THE TIME FUNCTION
		time(&tt);
		ti = localtime(&tt);
		cout << "Time Recorded: " << asctime(ti);
	}
};

int main() {

	Food_menu Obj;
	int A = 0;

	int arr_Item[3] = { 1,2,3 };  // CREATING THE ARRAYS FOR FOOD NUMBER
	int arr_Drink[3] = { 1,2,3 }; // CREATING THE ARRAYS FOR DRINK NUMBER

	Obj.Display();      // CALLING THE FUNCTION FOR DISPLAY

	char x;

	cout << "Would You Like to order something?(Y/N) ";  // ASKING  FOR ORDER
	cin >> x;
	do {


		if (x == 'N')
		{
			cout << "Thank You for Coming" << endl;
			break;

		}
		while (x != 'Y') {
			cout << "You entered Invalid Input" << endl;   // ERROR HANDLING
			cout << "Would You Like to order something(Y/N)? ";
			cin >> x;
		}

		int i, y=0, Y, W;


		while (x == 'Y')
		{
			cout << "Enter the Food Number from the menu: ";   // ASKING FOR FOOD NUMBER
			cin >> i;

			while (i != arr_Item[0] && i != arr_Item[1] && i != arr_Item[2]) {

				cout << "Wrong Input" << endl;      // ERROR HANDLING
				cout << "Enter the Food Number from the menu: ";
				cin >> i;


			}

			for (int j = 0; j < 3; j++)
				if (i == arr_Item[j]) {

					cout << "Enter the amount of the Quantity: "; // ASKING FOR QUANTITY
					cin >> Y;
					while (Y < 0) {
						cout << "Enter The positive Value " << endl;
						cin >> Y;
					}

					Obj.Set_Quantity(Y);   // CALLING THE QUANTITY SETTER FUNCTION
					Obj.Get_Quantity();
					if (i == arr_Item[0])
					{

						Obj.Price_of_item1();

					}
					else if (i == arr_Item[1])
					{
						Obj.Price_of_item2();
					}
					else if (i == arr_Item[2]) {
						Obj.Price_of_item3();
					}

				}
			cout << "Would You Like to Order Anything Else from the Food Menu?(Y/N)"; 
			cin >> x;
			if (x == 'N')
				break;
		}
		char D;
		cout << "Would You Like To have any Drinks? (Y/N)";  // ASKING FOR DRINKS   
		cin >> D;

		while (D != 'Y' && D != 'N') {  

			cout << "Invalid Input!" << endl;    // ERROR HANDLING
			cout << "Would You Like To have any Drinks? (Y/N)";
			cin >> D;
		}

		if (D == 'N') {

			Obj.Set_Drink_Quantity(0);   // if no drinks are4 being ordered then the value is nullified

			Obj.Get_drink_Quantity();

			Obj.Price_of_drink(y);
		}

		while (D == 'Y')

		{
			cout << "Enter the Drink Number from the menu: ";    //asking for the drink number
			cin >> W;
			while (W != arr_Drink[0] && W != arr_Drink[1] && W != arr_Drink[2]) {

				cout << "Wrong Input" << endl;
				cout << "Enter the Food Number from the menu: ";
				cin >> W;
			}

			for (int T = 0; T < 3; T++) {
				if (W == arr_Drink[T]) {

					cout << "Enter the amount of the Quantity: ";
					cin >> y;
					while (y < 0) {

						cout << "Enter the positive Value" << endl;
						cin >> y;
					}

					Obj.Set_Drink_Quantity(y);

					Obj.Get_drink_Quantity();

					Obj.Price_of_drink(y);
				}
			}
			cout << "Would You Like to Order Anything Else from the Food Menu? (Y/N)";
			cin >> x;
			if (x == 'N')
				break;
		}

		Obj.Set_itemNo(i);
		Obj.SetDrink_No(i);
		Obj.Get_itemNo();
		Obj.Get_itemPrice();
		Obj.Get_DrinkNo();
		Obj.Get_DrinkPrice();
                                        // bill display
		cout << "-------------------------------------------------------------" << endl;
		cout << setw(20) << "TOTAL BILL" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "Food Name" << setw(19) << "Amount" << setw(20) << "Quantity" << endl;
		if (i == arr_Item[0]) {

    	    cout << "Chicken Burger" << setw(12) << Obj.Price_of_item1() << setw(20) << Y << endl;
            cout << "Drinks" << setw(20) << Obj.Price_of_drink(y) << setw(20) << y << endl;
		}
		if (i == arr_Item[1]) {

			cout << "Sandwich" << setw(18) << Obj.Price_of_item2() << setw(20) << Y << endl;
			cout << "Drinks" << setw(20) << Obj.Price_of_drink(y) << setw(20) << y << endl;



		}
		if (i == arr_Item[2]) {

			cout << "Shawarma" << setw(19) << Obj.Price_of_item3() << setw(19) << Y << endl;
			cout << "Drinks" << setw(20) << Obj.Price_of_drink(y) << setw(20) << y << endl;
		}


        cout << "-------------------------------------------------------------" << endl;


		if (i == arr_Item[0]) {
			cout << "Total Price: " << Obj.Total_Price1() << endl;  // TOTAL PRICE DISPALY
			A = Obj.Total_Price1();
		}
		else   if (i == arr_Item[1]) {
			cout << "Total Price: " << Obj.Total_Price2() << endl;
			A = Obj.Total_Price2();
		}
		else  if (i == arr_Item[2]) {
			cout << "Total Price: " << Obj.Total_Price3() << endl;
			A = Obj.Total_Price3();
		}

		int h;
		cout << "Please the Pay price:";   // PAYING PRICE
		cin >> h;
		while (h < 0) {
			cout << "You have entered the negative value" << endl;
			cout << "Please the Pay price:";
			cin >> h;
		}
		while (h < A) {

			cout << "Lack of Money " << endl;
			cout << "Please the Pay price:";
			cin >> h;
		}
		if (h == A) {
			cout << "-------------------------------------------------------------" << endl;
			cout << "Your Change:" << 0.0 << endl;   // CHANGE BY DEFAULT
		
		}
		else if (h > A) {
			Obj.Amount_Change(A, h);
			cout << "-------------------------------------------------------------" << endl;
			cout << "Your Change:" << Obj.Amount_Change(A, h) << endl;
		}
		cout << "Your Order Number: " << Obj.Order_Number() << endl;  // ORDER NUMBER DISPLAY
		cout << "Serial Number: " << Obj.Serial_No() << endl;   // SERIAL NO DISPLAAY
		Obj.Time();
		cout << "Thank You For Coming " << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Next Costumer please. Would You Like to order Anything?(Y/N)";    // CONTINUING THE LOOP
		cin >> x;

	} while (x == 'Y');
	return 0;
}
