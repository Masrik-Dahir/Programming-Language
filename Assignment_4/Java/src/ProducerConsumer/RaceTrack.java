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

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.Random;

public class RaceTrack extends JPanel{

    // The directory of the image file (sportive-car.png)
    static String dir = "src/sportive-car.png";

    // static variables
    static BufferedImage img;
    static JPanel panel;
    static JButton start;
    static JButton pause;
    static JButton reset;
    static JFrame frame;
    static int car_1 = 20;
    static int car_2 = 20;
    static int car_3 = 20;
    static Thread driver_1;
    static Thread driver_2;
    static Thread driver_3;
    static boolean start_race = true;
    static Random random_value;
    static String first_car;
    static boolean end_race = false;

    public RaceTrack(){
        // Creating Panel
        panel = new JPanel();
        panel.setLayout(new FlowLayout());

        // Start button, light grey
        start=new JButton("Start");
        start.setBackground(Color.lightGray);
        start.setOpaque(true);
        start.setBorderPainted(false);
        start.setRolloverEnabled(true);

        // Pause Button, light grey
        pause=new JButton("Pause");
        pause.setBackground(Color.lightGray);
        pause.setOpaque(true);
        pause.setBorderPainted(false);

        // Reset Button, light grey
        reset=new JButton("Reset");
        reset.setBackground(Color.lightGray);
        reset.setOpaque(true);
        reset.setBorderPainted(false);

        // adding buttons to the panel
        button_click_functions();
        panel.add(start);
        panel.add(pause);
        panel.add(reset);
    }

    public static void thread(){

    }

    // Button click actions for the Richmond Raceway Interface
    public void button_click_functions(){

        // Getting a random value
        random_value = new Random();

        // When start button clicked
        start.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (!end_race){

                    // Creating thread for car_1
                    driver_1 = new Thread(new Runnable() {
                        @Override
                        public void run() {

                            // Getting a random value
                            random_value = new Random();

                            // Setting start rave to true for while loop to run
                            start_race = true;
                            while (start_race) {
                                try {
                                    // increasing the car movement by a random integer from 0 to 10 pixel
                                    int val = random_value.nextInt(11);
                                    car_1 += val;

                                    // Justifying if teh winner functoin applies
                                    winner();

                                    // If race is not over
                                    if (!end_race) {
                                        repaint();
                                    }

                                    // Sleep for 50 millisecond
                                    Thread.sleep(50);

                                    // If there is an interruption, stop
                                } catch (InterruptedException l) {

                                }
                            }
                        }
                    });

                    // Starting driver_1 thread
                    driver_1.start();

                    // Creating thread for car_2
                    driver_2 = new Thread(new Runnable() {
                        @Override
                        public void run() {

                            // Getting a random value
                            random_value = new Random();
                            while (start_race) {
                                try {
                                    // increasing the car movement by a random integer from 0 to 10 pixel
                                    int val = random_value.nextInt(11);
                                    car_2 += val;

                                    // Sleep for 50 millisecond
                                    Thread.sleep(50);

                                    // If there is an interruption, stop
                                } catch (InterruptedException l) {

                                }
                            }
                        }
                    });

                    // Starting driver_2 thread
                    driver_2.start();

                    // Creating thread for car_3
                    driver_3 = new Thread(new Runnable() {
                        @Override
                        public void run() {

                            // Getting a random value
                            random_value = new Random();
                            while (start_race) {
                                try {
                                    // increasing the car movement by a random integer from 0 to 10 pixel
                                    int val = random_value.nextInt(11);
                                    car_3 += val;

                                    // Sleep for 50 millisecon
                                    Thread.sleep(50);

                                    // If there is an interruption, stop
                                } catch (InterruptedException l) {

                                }
                            }
                        }
                    });

                    // Starting driver_3 thread
                    driver_3.start();


                }
            }

        });

        // If the pause button is clicked pause by setting start_race to false
        pause.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                start_race = false;
            }
        });

        // If the pause button is clicked reset car location to beginning
        reset.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                car_1 =20;
                car_2 =20;
                car_3 =20;
                start_race = false;
                end_race =false;
                repaint();

            }
        });
    }


    // Main function
    public static void main(String [] strings){

        // Creating frame object and setting its content as RaceTrack constructor
        frame = new JFrame();
        frame.setResizable(false);
        frame.setContentPane(new RaceTrack());

        // Adding panel
        frame.add(panel);

        // setting screen size to 500x200
        frame.setSize(500, 200);

        // Setting the title to "Richmond Raceway"
        frame.setTitle("Richmond Raceway");

        // Close when exited
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

    }

    public synchronized void winner(){

        // If any of the car enter finish line first (finish line -> 425)
        if (car_1 >= 425 || car_2 >= 425 || car_3 >= 425) {

            // If car_1 enter finish line first and has passed more distnace than car_2 and car_3
            if (car_1 >= 425 && car_1 > car_2 && car_1 > car_3) {
                first_car = "car1";
            }

            // If car_2 enter finish line first and has passed more distnace than car_1 and car_3
            else if (car_2 >= 425 && car_2 > car_1 && car_2 > car_3) {
                first_car = "car2";
            }

            // If car_3 enter finish line first and has passed more distnace than car_1 and car_2
            else if(car_3 >= 425 && car_3 > car_2 && car_3 > car_1) {
                first_car = "car3";
            }

            // Announcing who won the race
            JOptionPane.showMessageDialog(null,first_car+" won the race!");
            start_race = false;
            end_race =true;
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        // trying to load the image
        try {
            img = ImageIO.read(new File(dir));
        }catch (IOException e){
            System.out.println("\n\n dir variables in the top has invalid image directory.");
            System.exit(0);
        }

        // Setting color of the racetrack to light grey
        g.setColor(Color.LIGHT_GRAY);

        // drawing the rectangles
        g.drawRect(53,50,400,10);
        g.drawRect(53,100,400,10);
        g.drawRect(53,150,400,10);
        g.fillRect(53,50,400,10);
        g.fillRect(53,100,400,10);
        g.fillRect(53,150,400,10);
        g.drawImage(img, car_1, 39, this);
        g.drawImage(img, car_2,89, this);
        g.drawImage(img, car_3,139, this);
    }
}