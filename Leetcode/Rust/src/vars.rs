//variables hold primitive data or references to data
//variables are immutable by default
//rust is a block-scoped language

pub fn run() {
    let name = "Kang cilok";
    let mut age = 21;
    println!("My name is {0}, and i am age {1}", name, age);
    age = 38;
    println!("My name is {0}, and i am age {1}", name, age);

    
    const ID: i32 = 001;
    println!("ID: {}", ID);

    const ID2: i64 = 000002;
    println!("ID: {}", ID2);

    //Define constant with 
    const IDS: i32 = 000002;
    const IDT: f64 = 0.4;

    println!("IDS {}, IDT: {}",IDS, IDT);

      // Assign multiple vars
    let ( my_name, my_age ) = ("Brad", 37);
    println!("{} is {}", my_name, my_age );

    // penjumlahan vars

    let a = 2;
    let b = 3;

    println!("a + b = {}",a + b);

}