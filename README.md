# 🔄 NFA to DFA Converter

This project implements a conversion from a **Nondeterministic Finite Automaton (NFA)** to a **Deterministic Finite Automaton (DFA)** using C++.

The project combines both **theoretical concepts** from automata theory and their **practical implementation using classes and data structures**.

---

## 🚀 Purpose

The goal of this project is to:

- Understand the difference between NFA and DFA  
- Implement the **subset construction algorithm**  
- Practice object-oriented design and data structures  
- Apply theoretical computer science concepts in code  

This type of conversion is commonly used in:

- Compilers  
- Lexical analyzers  
- Pattern recognition systems  

---

## 🧠 Theory Overview

### 🔹 Nondeterministic Finite Automaton (NFA)

An NFA allows:

- Multiple transitions for the same input  
- Transitions to multiple states at once  


---

### 🔹 Deterministic Finite Automaton (DFA)

A DFA:

- Has exactly one transition per input symbol  
- Has no ambiguity in transitions  


## 🔄 Conversion Process (Step-by-Step)

### 1. Initial State

- Start with the **NFA start state**  
- This becomes the **first DFA state**  

---

### 2. State Expansion

For each DFA state:

- Take all NFA states inside it  
- For each input symbol:
  - Find all reachable states  
- Combine them into a new set  
- Add this set as a **new DFA state**  

---

### 3. Avoid Duplicates

- If a generated state already exists → **reuse it**  
- Otherwise → **store it as a new DFA state**  

---

### 4. Final States

A DFA state is **final** if:

- It contains **at least one final NFA state**  
