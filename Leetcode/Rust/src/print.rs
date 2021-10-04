pub fn run() {
    //cetak ke console
    println!("Hello World print.rs!");

    //basic formattion
    println!("Number {}", 1);

    //posisi argumen
    println!("{0} os from {1} and {0} likes to {2}", "Udin", "kocok","asik");

    //penamaan argumen

    println!("{name} likes to play {activity}",
    name = "john sins",
    activity = "coli"
    );

    //placeholder traits
    println!("Binary: {:b} Hex: {:x} Octal {:o}", 10, 10, 10);

    //placeholder for debug debug trait
    println!("{:?}", (12, true, "hello"));

    //matematika basic 
        //penjumlahan
        println!("10 + 10 = {}", 10 + 10);
    
        //perkalian
        println!("10 x 10 = {}", 10 * 10);

        //pembagian
        println!("20 : 10 = {}", 20 / 10);
    
        //matematika basic penjumlahan
        println!("9 % 2 = {}", 9 % 2);
}