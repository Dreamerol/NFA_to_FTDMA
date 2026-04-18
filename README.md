<h1 align="center">🔄 NFA → DFA CONVERTER – C++</h1> <h2 align="center"><strong><em style="font-size: 160%;">Educational project converting a Nondeterministic Finite Automaton into a Deterministic Finite Automaton using C++</em></strong></h2>


<img src="https://github.com/Dreamerol/Dreamerol/blob/df421c453532d5704df8b07a920be888da1bb5a5/CALCULATOR.jpg" alt="MATH" style="width:100%; height:auto;">

---

<div align="center">

  <!-- Core -->
  <img src="https://img.shields.io/badge/C%2B%2B-17-00A6FB?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/badge/Algorithms-Subset%20Construction-FB8500?style=for-the-badge">
  <img src="https://img.shields.io/badge/Automata-Theory-8338EC?style=for-the-badge">
  <img src="https://img.shields.io/badge/Data-Structures-06D6A0?style=for-the-badge">
  <img src="https://img.shields.io/badge/Python-Data%20Science-3A86FF?style=for-the-badge&logo=python&logoColor=white">
  <img src="https://img.shields.io/badge/NumPy-Numerical%20Computing-00B4D8?style=for-the-badge&logo=numpy&logoColor=white">
  <img src="https://img.shields.io/badge/Pandas-Data%20Analysis-52B788?style=for-the-badge&logo=pandas&logoColor=white">
  <img src="https://img.shields.io/badge/SQL-Database%20Query-4361EE?style=for-the-badge&logo=postgresql&logoColor=white">


</div>

---


<h2>📖 **Overview**</h2>

This project implements a conversion from a Nondeterministic Finite Automaton (NFA) to a Deterministic Finite Automaton (DFA) using C++.

It combines theoretical concepts from automata theory with practical implementation, demonstrating how nondeterministic systems can be systematically transformed into deterministic ones using classes, sets, and data structures.


---

<h2>🚀 **Purpose**</h2>

The main objectives of this project are to:

Understand the difference between NFA and DFA
Implement the subset construction algorithm
Practice working with data structures and structured program design
Apply theoretical computer science concepts in practice

---

Applications include:

🖥️ Compilers
🔍 Lexical analyzers
🧩 Pattern recognition systems

---

<div align="center">

  <!-- Core -->
  <img src="https://img.shields.io/badge/C%2B%2B-17-00A6FB?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/badge/Algorithms-Subset%20Construction-FB8500?style=for-the-badge">
  <img src="https://img.shields.io/badge/Automata-Theory-8338EC?style=for-the-badge">
  <img src="https://img.shields.io/badge/Data-Structures-06D6A0?style=for-the-badge">
  <img src="https://img.shields.io/badge/Python-Data%20Science-3A86FF?style=for-the-badge&logo=python&logoColor=white">
  <img src="https://img.shields.io/badge/NumPy-Numerical%20Computing-00B4D8?style=for-the-badge&logo=numpy&logoColor=white">
  <img src="https://img.shields.io/badge/Pandas-Data%20Analysis-52B788?style=for-the-badge&logo=pandas&logoColor=white">
  <img src="https://img.shields.io/badge/SQL-Database%20Query-4361EE?style=for-the-badge&logo=postgresql&logoColor=white">


</div>


---

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

---

<div align="center">

  <!-- Core -->
  <img src="https://img.shields.io/badge/C%2B%2B-17-00A6FB?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/badge/Algorithms-Subset%20Construction-FB8500?style=for-the-badge">
  <img src="https://img.shields.io/badge/Automata-Theory-8338EC?style=for-the-badge">
  <img src="https://img.shields.io/badge/Data-Structures-06D6A0?style=for-the-badge">
  <img src="https://img.shields.io/badge/Python-Data%20Science-3A86FF?style=for-the-badge&logo=python&logoColor=white">
  <img src="https://img.shields.io/badge/NumPy-Numerical%20Computing-00B4D8?style=for-the-badge&logo=numpy&logoColor=white">
  <img src="https://img.shields.io/badge/Pandas-Data%20Analysis-52B788?style=for-the-badge&logo=pandas&logoColor=white">
  <img src="https://img.shields.io/badge/SQL-Database%20Query-4361EE?style=for-the-badge&logo=postgresql&logoColor=white">


</div>

---

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

---

<div align="center">

  <!-- Core -->
  <img src="https://img.shields.io/badge/C%2B%2B-17-00A6FB?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/badge/Algorithms-Subset%20Construction-FB8500?style=for-the-badge">
  <img src="https://img.shields.io/badge/Automata-Theory-8338EC?style=for-the-badge">
  <img src="https://img.shields.io/badge/Data-Structures-06D6A0?style=for-the-badge">
  <img src="https://img.shields.io/badge/Python-Data%20Science-3A86FF?style=for-the-badge&logo=python&logoColor=white">
  <img src="https://img.shields.io/badge/NumPy-Numerical%20Computing-00B4D8?style=for-the-badge&logo=numpy&logoColor=white">
  <img src="https://img.shields.io/badge/Pandas-Data%20Analysis-52B788?style=for-the-badge&logo=pandas&logoColor=white">
  <img src="https://img.shields.io/badge/SQL-Database%20Query-4361EE?style=for-the-badge&logo=postgresql&logoColor=white">


</div>

---


<h2>💡 **Key Insight**</h2>

A DFA state is a set of NFA states.

This transformation removes nondeterminism and produces a deterministic automaton.

---

<h2>📌 **Notes**</h2>
Educational project focused on clarity and correctness
Advanced features like ε-transitions may be simplified
Emphasis on structured programming and algorithmic thinking

---

<h2>💡 **Learning Outcomes**</h2>

By completing this project, you will:

Understand NFA → DFA conversion
Implement theoretical algorithms in C++
Gain experience with sets, maps, and structured logic
Improve problem-solving and algorithmic thinking
Prepare a portfolio-ready, recruiter-friendly project

---

<div align="center">

<h2>🖥️ Tech Stack</h2> 


</div>


<div align="center">

  <!-- Core -->
  <img src="https://img.shields.io/badge/C%2B%2B-17-00A6FB?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/badge/Algorithms-Subset%20Construction-FB8500?style=for-the-badge">
  <img src="https://img.shields.io/badge/Automata-Theory-8338EC?style=for-the-badge">
  <img src="https://img.shields.io/badge/Data-Structures-06D6A0?style=for-the-badge">
  <img src="https://img.shields.io/badge/Python-Data%20Science-3A86FF?style=for-the-badge&logo=python&logoColor=white">
  <img src="https://img.shields.io/badge/NumPy-Numerical%20Computing-00B4D8?style=for-the-badge&logo=numpy&logoColor=white">
  <img src="https://img.shields.io/badge/Pandas-Data%20Analysis-52B788?style=for-the-badge&logo=pandas&logoColor=white">
  <img src="https://img.shields.io/badge/SQL-Database%20Query-4361EE?style=for-the-badge&logo=postgresql&logoColor=white">


</div>

---

<h2>💼 **Key Skills**</h2>

- 🐍 **C++ Programming & OOP**  
- 🧩 **Algorithm Implementation**  
- 🗂️ **Data Structures:** sets, maps  
- 🖥️ **Console Application Development**  
- 🧠 **Problem-Solving & Logical Thinking**  
- 📊 **Structured Program Design & Debugging**

---

<div align="center">

  <!-- Core -->
  <img src="https://img.shields.io/badge/C%2B%2B-17-00A6FB?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/badge/Algorithms-Subset%20Construction-FB8500?style=for-the-badge">
  <img src="https://img.shields.io/badge/Automata-Theory-8338EC?style=for-the-badge">
  <img src="https://img.shields.io/badge/Data-Structures-06D6A0?style=for-the-badge">
  <img src="https://img.shields.io/badge/Python-Data%20Science-3A86FF?style=for-the-badge&logo=python&logoColor=white">
  <img src="https://img.shields.io/badge/NumPy-Numerical%20Computing-00B4D8?style=for-the-badge&logo=numpy&logoColor=white">
  <img src="https://img.shields.io/badge/Pandas-Data%20Analysis-52B788?style=for-the-badge&logo=pandas&logoColor=white">
  <img src="https://img.shields.io/badge/SQL-Database%20Query-4361EE?style=for-the-badge&logo=postgresql&logoColor=white">


</div>

---

💡 **This project demonstrates:** practical application of C++ and OOP, subset construction algorithm, and NFA → DFA conversion, while being portfolio-ready and optimized for HR & recruiter impact.


<p align="center">
  🔗 Explore more on my GitHub profile: 
  <a href="https://github.com/Dreamerol">github.com/Dreamerol</a>
</p>

