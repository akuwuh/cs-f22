/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// No One
//
// Name: Isaac Nguyen
// login ID: i3nguyen
//////////////////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

bool active = false;
const int max_points = 10000;
int card_number = 0;
int card_pin_number = 0;
int bal = 0;
int purchases = 0;

int count_dig(int num) {
    int counter = 0;
     
    if (num>0) {
        counter++;
        return counter + count_dig(num/10);
    } else {
        return 0;
    }


}


void activate(const int card_num, const int card_pin) {
  // Error messages
  // "An error occurred activating the card.\n"
  // "The card is already activated.\n"
  // "The card number is not an 8-digit integer.\n"
  // "The card pin is not an 4-digit integer.\n"
  
  if (active == true || count_dig(card_num) != 8 || count_dig(card_pin) != 4) {
      printf("An error occurred activating the card.\n");
      
      if (active == true) {
          printf("The card is already activated.\n");
      } 
      
      if (count_dig(card_num) != 8 ) {
          printf("The card number is not an 8-digit integer.\n");
      } 
      
      if (count_dig(card_pin) != 4) {
          printf("The card pin is not an 4-digit integer.\n");
      }
  }
  
  else {
      printf("The card has been activated successfully.\n");
      active = true;
      card_number = card_num;
      card_pin_number = card_pin;
  }
  // Success message
  // "The card has been activated successfully.\n" 
}

void cancel(const int card_num) {
  // Error messages
  // "An error occurred canceling the card.\n"
  // "The card is inactive.\n"
  // "The card number provided is incorrect.\n"
  if (card_number != card_num || active == false) {
      printf("An error occurred canceling the card.\n");
      
      if (active == false) {
          printf("The card is inactive.\n");
      }
      
      if (card_number != card_num) {
          printf("The card number provided is incorrect.\n");
      }
  } else {
      int cb = (bal*2)/100;
      int cent_first = cb%10;
      int cent_second = (cb/10)%10;
      int dollar = cb/100;
      
      printf("The card has been canceled successfully.\n");
      printf("You will receive $%d.%d%d for the outstanding points balance of %d.\n", dollar, cent_second, cent_first, bal);
      active = false;
  }
  // Success messages
  // "The card has been canceled successfully.\n"
  // "You will receive $X.XX for the outstanding points balance of XXX.\n"
}

void print_balance(void) {
  // Error message
  // "The card is inactive.\n"
  int cb = (bal*2)/100;
  int cent_first = cb%10;
  int cent_second = (cb/10)%10;
  int dollar = cb/100;
  
  if(active == false) {
      printf("The card is inactive.\n");
  } else {
      printf("Your points balance is %d and your cash back balance is $%d.%d%d.\n", bal, dollar, cent_second, cent_first);
  }

  // Success message
  // "Your points balance is XXX and your cash back balance is $X.XX.\n"

}

void purchase(const int card_pin, const int amount) {
  // Error messages
  // "An error occurred making a purchase.\n"
  // "The card is inactive.\n"
  // "You entered an incorrect PIN.\n"
  // "The purchase amount is not positive.\n"
  int cb = (bal*2) /100;
  int cent_first = cb%10;
  int cent_second = (cb/10)%10;
  int dollar = cb/100;
    
  if(active == false || card_pin != card_pin_number || amount <=0) {
    
      printf("An error occurred making a purchase.\n");
      if (active == false) {
          printf("The card is inactive.\n");
      }
      
      if (card_pin != card_pin_number) {
          printf("You entered an incorrect PIN.\n");
      }
      
      if (amount <=0) {
          printf("The purchase amount is not positive.\n");
      }
  } else {
      if(amount + bal > max_points || amount == 10) {
          if(bal > 0) {
            printf( "You redeemed %d points for $%d.%d%d cash back.\n", bal, dollar, cent_second, cent_first);
            bal = 0;
            purchases = 0;
          }
      }
      
      
      printf("You made a purchase of $%d.%d%d.\n", amount/100, (amount/10)%10, amount%10);
      bal += amount;
      cb = (bal*2) /100;
      cent_first = cb%10;
      cent_second = (cb/10)%10;
      dollar = cb/100;
      printf("Your points balance is %d and your cash back balance is $%d.%d%d.\n", bal, dollar, cent_second, cent_first);
      
  }
  
  

  // Success messages
  // "You made a purchase of $X.XX.\n"
  // "Your points balance is XXX and your cash back balance is $X.XX.\n"
  // "You redeemed XXX points for $X.XX cash back.\n"
}

void sell(const int paperbacks, const int hardcovers) {
  // Error messages
  // "An error occurred making a sale.\n"
  // "The card is inactive.\n"
  // "The number of paperbacks is not positive.\n"
  // "The number of hard covers is not positive.\n"
  
  int cb =0;
  int cent_first =0;
  int cent_second = 0;
  int dollar = 0;
  
  if(paperbacks < 0 || hardcovers < 0 || active == false) {
      printf("An error occurred making a sale.\n");
      
      if(active == false) {
         printf("The card is inactive.\n"); 
      }
      if(paperbacks < 0) {
          printf("The number of paperbacks is not positive.\n");
      }
      if(hardcovers < 0) {
          printf("The number of paperbacks is not positive.\n");
      }
      
  } else {
      int points = paperbacks*75 + hardcovers*170;
      
      if (points + bal > max_points) {
          if(bal > 0) {
              
            cb = (bal*2) /100;
            cent_first = cb%10;
            cent_second = (cb/10)%10;
            dollar = cb/100;
            
            printf( "You redeemed %d points for $%d.%d%d cash back.\n", bal, dollar, cent_second, cent_first);
            bal = 0;
          }
      }
      
      
      printf("You earned %d points making a sale.\n", points);
      bal += points;
      cb = (bal*2) /100;
      cent_first = cb%10;
      cent_second = (cb/10)%10;
      dollar = cb/100;
      printf("Your points balance is %d and your cash back balance is $%d.%d%d.\n", bal, dollar, cent_second, cent_first);
      
      
      
      
      
      
      
  }

  // Success messages
  // "You earned XXX points making a sale.\n"
  // "Your points balance is XXX and your cash back balance is $X.XX.\n"
  // "You redeemed XXX points for $X.XX cash back.\n"
}


/////////////////////////////////////////////
// DO NOT MODIFY THE CODE BELOW
/////////////////////////////////////////////

// help() displays all the valid commands for I/O tests.
// effects: produces output.
void help(void) {
  printf("Valid commands are:\n");
  printf("activate card_num card_pin - calls activate(card_num, card_pin)\n");
  printf("cancel card_num - calls cancel(card_num)\n");
  printf("balance - calls balance()\n");
  printf("purchase pin amount - calls purchase(pin, amount)\n");
  printf("pay amount - calls payment(amount)\n");
  printf("help - prints this information\n");
  printf("quit - ends the test\n");
}

int main(void) {

  const int ACTIVATE = lookup_symbol("activate");
  const int CANCEL = lookup_symbol("cancel");
  const int BALANCE = lookup_symbol("balance");
  const int PURCHASE = lookup_symbol("purchase");
  const int SELL = lookup_symbol("sell");
  const int QUIT = lookup_symbol("quit");
  const int HELP = lookup_symbol("help");

  int cmd = 0;

  while (1) {
    cmd = read_symbol();
    if (cmd == QUIT) {
      break;
    } else if (cmd == HELP) {
      help();
    } else if (cmd == ACTIVATE) {
      int num = read_int();
      int pin = read_int();
      activate(num, pin);
    } else if (cmd == CANCEL) {
      int num = read_int();
      cancel(num);
    } else if (cmd == BALANCE) {
      print_balance();
    } else if (cmd == PURCHASE) {
      int pin = read_int();
      int amount = read_int();
      purchase(pin, amount);
    } else if (cmd == SELL) {
      int paperbacks = read_int();
      int hardcovers = read_int();
      sell(paperbacks, hardcovers);
    } else {
      printf("Unexpected command: ");
      print_symbol(cmd);
      printf("\n");
      break;
    } 
  }
}