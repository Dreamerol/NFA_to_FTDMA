## 🔄 Discrete Math - NFA to DFA Converter Discrete Mathematics & Automata Theory | NFA to DFA Converter

---

---

## 📖 **Overview**
This project implements a conversion from a **Nondeterministic Finite Automaton (NFA)** to a **Deterministic Finite Automaton (DFA)** using C++.

It combines both **theoretical concepts from automata theory** and their **practical implementation using classes and data structures**, providing a clear understanding of how nondeterministic systems can be transformed into deterministic ones.

---

## 🚀 Purpose

The main objectives of this project are to:

- Understand the difference between **NFA** and **DFA**  
- Implement the **subset construction algorithm**  
- Practice working with **data structures** and structured program design  
- Apply theoretical computer science concepts in a practical context  

This type of conversion is widely used in:

- Compilers  
- Lexical analyzers  
- Pattern recognition systems  

---

## 🧠 Theory Overview

### 🔹 Nondeterministic Finite Automaton (NFA)

An NFA is a computational model that allows:

- Multiple transitions for the same input symbol  
- Transitions to several states simultaneously  

This means the next state is **not uniquely determined**.

---

### 🔹 Deterministic Finite Automaton (DFA)

A DFA is a computational model where:

- Each state has exactly **one transition per input symbol**  
- There is **no ambiguity** in state transitions  

This makes DFAs easier to simulate and implement.

---

## ⚙️ Algorithm Used

The conversion is based on the **subset construction algorithm**, where:

> Each state in the DFA represents a **set of states from the NFA**.

This approach eliminates nondeterminism by grouping all possible states into a single deterministic state.

---

## 🔄 Conversion Process (Step-by-Step)

### 1. Initial State

- Start with the **NFA start state**  
- This becomes the **first DFA state**  

---

### 2. State Expansion

For each DFA state:

- Take all NFA states contained in it  
- For each input symbol:
  - Find all reachable states from those NFA states  
- Combine the results into a new set  
- Add this set as a **new DFA state**  

---

### 3. Avoid Duplicates

- If a generated state already exists → **reuse it**  
- Otherwise → **store it as a new DFA state**  

This ensures the DFA contains only **unique states**.

---

### 4. Final States

A DFA state is marked as **final** if:

- It contains **at least one final state from the NFA**  

---

## 💡 Key Insight

> The core idea of the algorithm is:
>
> **A DFA state is a set of NFA states.**

This transformation is what removes nondeterminism and makes the automaton deterministic.

---

## 📌 Notes

- This project is intended for **educational purposes**  
- The focus is on **clarity and correctness**, not optimization  
- Some advanced features (like ε-transitions) may be simplified or not included  

---

## 💡 Learning Outcomes

By completing this project, you will:

- Understand how NFAs are converted into DFAs  
- Learn how to implement theoretical algorithms in C++  
- Gain experience with sets, maps, and structured logic  
- Improve problem-solving and algorithmic thinking  


