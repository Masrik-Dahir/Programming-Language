package ProducerConsumer;/*
----------------------------------------------------
Masrik Dahir
Date: 04/15/2022

---------------------------------------------------
Usage Guide
(1) javac RaceTrack.java
(2) java RaceTrack

----------------------------------------------------
 */
import java.util.Random;
import java.util.concurrent.locks.ReentrantLock;

public class FoodConsumer extends Thread {

    // single instance variable bank
    private FoodBank bank;

    // Constructor for FoodConsumer
    public FoodConsumer(FoodBank bank) {
        this.bank = bank;
    }

    // run the FoodConsumer thread
    public void run() {

        // declaring quantity variable
        int quantity;

        // Creating Random object
        Random random = new Random();

        // Creating ReentrantLock object
        ReentrantLock reentrant_lock = new ReentrantLock();

        // Always true (infinity loop of consumer thread)
        while (true) {

            // getting a quantity from 1 to 100
            quantity = random.nextInt(100) + 1;
            System.out.println("Waiting to take food");

            // locking the reentrant_lock
            reentrant_lock.lock();

            // If quantity of food is greater than the food storage, we cancel the transaction
            if (bank.getFood() >= quantity) {
                bank.takeFood(quantity);
            }

            // Unlock the reentrant_lock
            reentrant_lock.unlock();

            // Sleep for 100 millisecond
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

}