use std::f32::consts::PI;

trait Shape{
    fn area(&self)->f32;
    fn parimeter(&self)->f32;
}

struct Rect{
    width: f32,
    height: f32,
}

struct Circle{
    radius: f32,
}

impl Shape for Rect{

    fn area(&self)->f32{
        return self.width * self.height;

    }
    fn parimeter(&self)-> f32{
        return 2.0 *(self.width + self.height);
    }
}

impl  Shape for Circle {
    fn area(&self)->f32 {
        return  PI * self.radius* self.radius;
    }
    fn parimeter(&self)->f32 {
        return 2.0 * PI * self.radius;
    }
    
}
fn main(){
    let r = Rect{
        height: 10.0,
        width: 20.0
    };
    let c: Circle = Circle { radius: 5.0};
    println!("{}", get_area(&r));
    println!("{}", get_area(&c));
    println!("{}", get_perimeter(&r));
    println!("{}", get_perimeter(&c));
}

fn get_area<T:Shape>(shape:&T)-> f32{
    return shape.area();
}

fn get_perimeter<T:Shape>(shape:&T)->f32{
    return  shape.parimeter();
}