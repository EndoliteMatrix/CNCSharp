use serde::{Serialize, Deserialize};

#[derive(Debug, Serialize, Deserialize)]
pub struct Program {
    pub operations: Vec<Operation>,
}

#[derive(Debug, Serialize, Deserialize)]
pub enum Operation {
    Move { x: f64, y: f64, z: f64, feed_rate: Option<f64> },
    SetTemperature { target: f64 },
    Comment { text: String },
    // Additional operations can be added here
}
