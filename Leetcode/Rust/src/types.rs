pub fn run() {
    //default id "i32"
    let x = 1;

    //default is "f64"
    let y = 2.5;

    //ADD Explicit type

    let z: i64 = 4545445454545;

    println!("max i32: {}", std::i32::MAX);
    println!("max i32: {}", std::i64::MAX);

    //Boolean 
    let is_active = true;

    println!("{:?}", (x, y, z, is_active));

    //Boolean 2

    let is_active: bool = true;

    // Get boolean from expression
    let is_greater: bool = 10 < 5;

    let a1 = 'a';
    let face = '\u{1F600}';

    println!("{:?}", (x, y, z, is_active, is_greater, a1, face));
}