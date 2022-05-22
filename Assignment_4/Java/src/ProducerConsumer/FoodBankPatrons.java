package ProducerConsumer;/*
----------------------------------------------------
Masrik Dahir
Date: 04/15/2022

---------------------------------------------------
Usage Guide
(1) javac FoodBankPatrons.java
(2) java FoodBankPatrons

----------------------------------------------------
 */
import java.util.Random;
import java.util.concurrent.locks.ReentrantLock;

public class FoodBankPatrons {

    public static void main(String[] argv) {

        // Creating FoodBank object
        FoodBank bank = new FoodBank();

        // Creating FoodProducer object
        FoodProducer food_producer = new FoodProducer(bank);

        // Creating FoodConsumer object
        FoodConsumer food_consumer = new FoodConsumer(bank);

        // Starting FoodProducer and FoodConsumer thread
        food_producer.start();
        food_consumer.start();

    }
}