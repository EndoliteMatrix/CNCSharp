pub mod ir;
pub mod parser;

use log::info;

/// Initialize logging for the parser.
/// This function sets up env_logger so that log messages
/// from the parser and backend are visible when running the program.
pub fn init_logging() {
    let _ = env_logger::builder().is_test(false).try_init();
    info!("Logging initialized");
}

// Re-export IR types for convenience
pub use ir::{Program, Operation};
