package ProducerConsumer;

/*
----------------------------------------------------
Masrik Dahir
Date: 04/15/2022

---------------------------------------------------
 */
public class FoodBank {

    // Single instance variable FoodBank
    private int food;

    // Constructor for FoodBank
    public FoodBank() {
        food = 0;
    }

    // Getter for food
    public int getFood(){
        return food;
    }

    // Food Taking Thread
    public void takeFood(int quantity) {
        System.out.printf("Taking %d items of food, the balance is now %d items.\n", quantity, food);

        // If quantity is equal to less than food storage
        if (food >= quantity){
            food -= quantity;
        }
    }

    // Food Giving Thread
    public void giveFood(int quantity) {
        System.out.printf("Getting %d items of food, the balance is now %d items.\n", quantity, food);
        food += quantity;
    }
}