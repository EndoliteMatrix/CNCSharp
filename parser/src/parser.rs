use crate::ir::{Program, Operation};
use thiserror::Error;
use log::{info, warn, error};

/// Represents errors that can occur during parsing CNCSharp source code.
#[derive(Debug, Error)]
pub enum ParserError {
    /// The input ended unexpectedly.
    #[error("unexpected end of input")]
    UnexpectedEof,
    /// An invalid token was encountered on a specific line.
    #[error("invalid token at line {line}: {message}")]
    InvalidToken { line: usize, message: String },
    /// A catch-all for other kinds of parse errors.
    #[error("other error: {0}")]
    Other(String),
}

/// Parses CNCSharp source code into an intermediate representation (IR).
///
/// This function takes the raw source string and produces a `Program` containing
/// `Operation` values. Each operation corresponds to a high-level instruction
/// in the CNCSharp language. The parser is currently simplistic; it logs its
/// actions and treats blank lines and lines starting with comment markers as
/// comments. Any other instruction is currently unsupported and will result
/// in an `InvalidToken` error. As the language matures, this function will
/// perform real lexical analysis and parsing.
pub fn parse_source(source: &str) -> Result<Program, ParserError> {
    info!("Starting parse of source with {} bytes", source.len());
    let mut program = Program { operations: Vec::new() };
    for (line_index, line) in source.lines().enumerate() {
        let trimmed = line.trim();
        if trimmed.is_empty() {
            // Skip empty lines
            continue;
        }
        if trimmed.starts_with("//") || trimmed.starts_with(";") {
            // Treat as a comment operation
            program.operations.push(Operation::Comment(trimmed.to_string()));
            continue;
        }
        // TODO: Add real parsing of instructions here
        warn!("Unrecognized instruction on line {}: {}", line_index + 1, trimmed);
        return Err(ParserError::InvalidToken {
            line: line_index + 1,
            message: format!("unrecognized instruction '{}'", trimmed),
        });
    }
    info!("Finished parsing successfully");
    Ok(program)
}
