<h1 align="center">🔄 NFA → DFA CONVERTER – C++</h1> <p align="center"><strong><em style="font-size: 160%;">Educational project converting a Nondeterministic Finite Automaton into a Deterministic Finite Automaton using C++</em></strong></p>


<img src="https://github.com/Dreamerol/Dreamerol/blob/3fcda6de47c889eaa8a1706f9cdf829c823b5a63/MATH4.JPG" alt="MATH" style="width:100%; height:auto;">

---

<p align="center"> <img src="https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++"> <img src="https://img.shields.io/badge/Algorithms-Subset_Construction-yellow?style=for-the-badge" alt="Algorithms"> <img src="https://img.shields.io/badge/Automata-Theory-purple?style=for-the-badge" alt="Automata Theory"> <img src="https://img.shields.io/badge/Data-Structures-green?style=for-the-badge" alt="Data Structures"> <img src="https://img.shields.io/badge/Console-App-lightgrey?style=for-the-badge" alt="Console App"> <img src="https://img.shields.io/badge/Educational-Purpose-red?style=for-the-badge" alt="Educational"> </p>
<h2>📖 **Overview**</h2>

This project implements a conversion from a Nondeterministic Finite Automaton (NFA) to a Deterministic Finite Automaton (DFA) using C++.

It combines theoretical concepts from automata theory with practical implementation, demonstrating how nondeterministic systems can be systematically transformed into deterministic ones using classes, sets, and data structures.

<h2>🚀 **Purpose**</h2>

The main objectives of this project are to:

Understand the difference between NFA and DFA
Implement the subset construction algorithm
Practice working with data structures and structured program design
Apply theoretical computer science concepts in practice

Applications include:

🖥️ Compilers
🔍 Lexical analyzers
🧩 Pattern recognition systems
<h2>🧠 **Theory Overview**</h2>
🔹 Nondeterministic Finite Automaton (NFA)

An NFA allows:

Multiple transitions for the same input symbol
Transitions to several states simultaneously

The next state is not uniquely determined.

🔹 Deterministic Finite Automaton (DFA)

A DFA ensures:

Each state has exactly one transition per input symbol
There is no ambiguity in transitions

DFAs are easier to simulate and implement.


<h2>⚙️ **Algorithm Used**</h2>

The conversion uses the subset construction algorithm, where:

Each DFA state represents a set of NFA states.

This eliminates nondeterminism by grouping all possible states into a single deterministic state.


Step-by-Step Summary (Emoji Style)

1️⃣ Initial State – Start with the NFA start state → First DFA state
2️⃣ State Expansion – For each DFA state, compute all reachable states for every input symbol
3️⃣ Avoid Duplicates – Reuse existing DFA states to ensure uniqueness
4️⃣ Final States – Mark DFA states as final if containing any NFA final state
5️⃣ Result – Fully deterministic DFA ready for simulation or analysis


<h2>💡 **Key Insight**</h2>

A DFA state is a set of NFA states.

This transformation removes nondeterminism and produces a deterministic automaton.


<h2>📌 **Notes**</h2>
Educational project focused on clarity and correctness
Advanced features like ε-transitions may be simplified
Emphasis on structured programming and algorithmic thinking
<h2>💡 **Learning Outcomes**</h2>

By completing this project, you will:

Understand NFA → DFA conversion
Implement theoretical algorithms in C++
Gain experience with sets, maps, and structured logic
Improve problem-solving and algorithmic thinking
Prepare a portfolio-ready, recruiter-friendly project

<h2>🖥️ **Tech Stack / ТЕХНОЛОГИИ**</h2> <p align="center"> <img src="https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++"> <img src="https://img.shields.io/badge/Algorithms-yellow?style=for-the-badge" alt="Algorithms"> <img src="https://img.shields.io/badge/Data-Structures-green?style=for-the-badge" alt="Data Structures"> <img src="https://img.shields.io/badge/Classes-OOP-purple?style=for-the-badge" alt="OOP"> <img src="https://img.shields.io/badge/Console-App-lightgrey?style=for-the-badge" alt="Console App"> <img src="https://img.shields.io/badge/Problem-Solving-blueviolet?style=for-the-badge" alt="Problem Solving"> <img src="https://img.shields.io/badge/Algorithmic-Thinking-orange?style=for-the-badge" alt="Algorithmic Thinking"> </p>

<h2>💼 **Key Skills**</h2>

- 🐍 **C++ Programming & OOP**  
- 🧩 **Algorithm Implementation**  
- 🗂️ **Data Structures:** sets, maps  
- 🖥️ **Console Application Development**  
- 🧠 **Problem-Solving & Logical Thinking**  
- 📊 **Structured Program Design & Debugging**

---

💡 **This project demonstrates:** practical application of C++ and OOP, subset construction algorithm, and NFA → DFA conversion, while being portfolio-ready and optimized for HR & recruiter impact.
