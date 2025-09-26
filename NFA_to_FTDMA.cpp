// NFA_to_MTDA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
struct State;
std::vector<State*> empty = {  };

struct State {

    std::pair<char, std::vector<State*>> transitionA;
    std::pair<char, std::vector<State*>> transitionB;
    int ID;
    static int Id;
    bool isFinal=false;
    bool isStart = false;

    State() {
        ID = Id++;
        this->transitionA.first = 'a';
        this->transitionB.first = 'b';
        this->transitionA.second = empty;
        this->transitionB.second = empty;

    }
    State(std::vector<State*>& vec1, std::vector<State*>& vec2) {
        this->transitionA.first = 'a';
        this->transitionB.first = 'b';
        ID = Id++;
        for (int i = 0;i < vec1.size();i++) {
            transitionA.second.push_back(vec1[i]);
        }
        for (int i = 0;i < vec2.size();i++) {
            transitionB.second.push_back(vec2[i]);;
        }
    }
    bool isThere(std::vector<State*>& vec, State*& newState) {
        for (int i = 0;i < vec.size();i++) {
            if (vec[i] == newState) {
                return 1;
            }
        }
        return 0;
    }

    void addHelper(std::vector<State*>& vec, State*& newState)
    {
        if (isThere(vec, newState)) {
            return;
        }
        vec.push_back(newState);
    }

    void addTransition(char el, State*& newState) {
        if (el != 'a' && el != 'b') {
            throw std::logic_error("Invalid symbol");
        }
        else if (el == 'a') {
            addHelper(this->transitionA.second, newState);
        }
        else {
            addHelper(this->transitionB.second, newState);
        }
    }
    void print() {
        std::cout << this->ID << " ->a ";
        for (int i = 0;i < this->transitionA.second.size();i++) {

            std::cout << this->transitionA.second[i]->ID << " ";
        }
        std::cout << '\n';
        std::cout << this->ID << " ->b ";
        for (int i = 0;i < this->transitionB.second.size();i++) {

            std::cout << this->transitionB.second[i]->ID << " ";
        }
        std::cout<<'\n'<<"isFinal - "<< this->isFinal;
     
        std::cout << '\n';
    }

};

void createEmptySet(State& emptySet) {
    emptySet.ID = 0;
    emptySet.transitionA.second.push_back(&emptySet);
    emptySet.transitionB.second.push_back(&emptySet);
    
}

int State::Id = 1;

void swapStates(State*& one, State*& two) {
    State* help = one;
    one = two;
    two = help;
}
void sortStates(std::vector<State*>& states) {
  //  std::vector<State*> newStates;
    for (int i = 0;i < states.size() - 1;i++) {
        int minidx = i;
        for (int j = i + 1;j < states.size();j++) {
            if (states[minidx]->ID > states[j]->ID) {
                minidx = j;
            }
        }
        if (minidx != i) {
            swapStates(states[i], states[minidx]);
        }
    }
  

}
bool isThere(std::vector<State*>& vec, State* ptr) {
    for (int i = 0;i < vec.size();i++) {
        if (vec[i] == ptr) {
            return 1;
        }
    }
    return 0;
}
//TOTALIZATION
void Totalization(std::vector<State*>& states, State& emptySet) {
    bool flag = false;
    for (int i = 0;i < states.size();i++) {
        if (states[i]->transitionA.second.empty()) {
            flag = true;
            states[i]->transitionA.second.push_back(&emptySet);
        }
        if (states[i]->transitionB.second.empty()) {
            flag = true;
            states[i]->transitionB.second.push_back(&emptySet);
        }
    }
    if (flag) {
        states.push_back(&emptySet);
    }
    std::cout << "Totalization" << '\n';
    for (int j = 0;j < states.size();j++) {
        states[j]->print();
    }
}
//some help functions
bool areTheSame(std::vector<State*> one, std::vector<State*> two) {
    if (one.size() != two.size()) {
        return 0;
    }
    sortStates(one);
    sortStates(two);
    for (int i = 0;i < one.size();i++) {
        if (one[i] != two[i]) {
            return 0;
        }
    }
    return 1;
}
bool SubsetIsThere(std::queue<std::vector<State*>> vec, std::vector<State*>& subvec) {
    while (!vec.empty()) {
        if (areTheSame(vec.front(), subvec)) return 1;
        vec.pop();
    }
    return 0;

}
bool SubsetIsTherePrim(std::vector<std::vector<State*>>& vec, std::vector<State*>& subvec) {
    for (int h = 0;h < vec.size();h++) {
        if (areTheSame(vec[h], subvec)) return 1;

    }
    return 0;

}

void vectorsMerged(std::vector<State*>& one, std::vector<State*> two) {

    for (int i = 0;i < two.size();i++) {
        if (!isThere(one, two[i])) one.push_back(two[i]);
    }

    sortStates(one);


}


int idx(std::vector<std::vector<State*>> vec, std::vector<State*> subvec) {
    for (int h = 0;h < vec.size();h++) {
        if (areTheSame(vec[h], subvec)) return h;

    }
    return -1;
}

bool checkIsFinalSet(std::vector<State*>& states) {
    for (int i = 0;i < states.size();i++) {
        if (states[i]->isFinal) {
            return true;
        }
    }
    return false;
}
int startIdx(std::vector<State*>& states) {
    for (int i = 0;i < states.size();i++) {
        if (states[i]->isStart) {
            return i;
        }
    }
    return -1;
}
//DETERMINIZATION
void determinization(std::vector<State*>& states) {

    std::vector<std::vector<State*>> finalStates;
    int start = startIdx(states);
    if (start == -1) {
        throw std::out_of_range("Out of range");
    }
    finalStates.push_back({ states[start] });

    std::queue<std::vector<State*>> q;
    
    std::vector<State*> curr = { states[start] };
    q.push(curr);
    bool f = false;
    while (true) {
        if (q.empty()) {
            break;
        }

        curr = q.front();
        
        std::vector<State*> startA;
        std::vector<State*> startB;
        for (int j = 0;j < curr.size();j++) {
            vectorsMerged(startA, curr[j]->transitionA.second);
            vectorsMerged(startB, curr[j]->transitionB.second);
        }
        
        sortStates(startA);  
        sortStates(startB);
      
      
       /* for (int i = 0;i < curr.size();i++) {
            std::cout << curr[i]->ID << ' ';
        }
        std::cout << "->a ";
        for (int i = 0;i < startA.size();i++) {
            std::cout << startA[i]->ID << ' ';
        }
        std::cout << '\n' << "  ->b ";
        for (int i = 0;i < startB.size();i++) {
            std::cout << startB[i]->ID << ' ';
        }
        std::cout << '\n';*/
        if (!SubsetIsThere(q, startA) && !SubsetIsTherePrim(finalStates, startA)) {
            
            
            q.push(startA);
            finalStates.push_back(startA);
           
            
        }
        if (!SubsetIsThere(q, startB) && !SubsetIsTherePrim(finalStates, startB)) {
            
            
            q.push(startB);
            finalStates.push_back(startB);
         

            
        }
        q.pop();

    }

    std::vector<State*> finals(finalStates.size());
    for (int i = 0;i < finals.size();i++) {
        finals[i] = new State();
        finals[i]->ID = i + 1;
    }


    for (int i = 0;i < finalStates.size();i++) {
        std::vector<State*> startA;
        std::vector<State*> startB;
        for (int j = 0;j < finalStates[i].size();j++) {
            vectorsMerged(startA, finalStates[i][j]->transitionA.second);
            vectorsMerged(startB, finalStates[i][j]->transitionB.second);
        }
       
        bool checkB = checkIsFinalSet(startB);

        int idxA = idx(finalStates, startA);
        int idxB = idx(finalStates, startB);
        if (idxA == -1 || idxB == -1) {
            throw std::out_of_range("Invalid idx");
        }

        if (checkIsFinalSet(startA)) {
            finals[idxA]->isFinal = true;
        }
        if (checkIsFinalSet(startB)) {
            finals[idxA]->isFinal = true;
        }

        finals[i]->transitionA.second.push_back(finals[idxA]);
        finals[i]->transitionB.second.push_back(finals[idxB]);

    }
    std::cout << "--------------------------------------------------"<<'\n';
    std::cout << "Determinization" << '\n';
    for (int j = 0;j < finals.size();j++) {
        finals[j]->print();
    }
    states = finals;

}
bool isThereInt(std::vector<int>& nums, int ID) {
    for (int i = 0;i < nums.size();i++) {
        if (nums[i] == ID) {
            return 1;
        }
    }
    return 0;
}
int idxOfClass(std::vector<std::vector<int>>& classes, int ID) {
    for (int i = 0;i < classes.size();i++) {
        if (isThereInt(classes[i], ID)) {
            return i;
        }
    }
    return -1;
}
void pairsOfClasses(std::vector<std::vector<int>>& classes,std::vector<std::pair<int, int>>& pairs,
    std::vector<std::pair<int, int>>& MainPairs) {
    for (int j = 0;j < MainPairs.size();j++) {
        pairs[j].first = idxOfClass(classes, MainPairs[j].first) + 1;
        pairs[j].second = idxOfClass(classes, MainPairs[j].second) + 1;
       
    }
 
}
bool isTherePair(std::vector<std::pair<int, int>>& pairs, std::pair<int, int> p) {
    for (int i = 0;i < pairs.size();i++) {
        if (pairs[i] == p) return true;
    }
    return false;
}
std::vector<std::pair<int, int>> uniquePairs(std::vector<std::pair<int, int>>& pairs) {
    std::vector<std::pair<int, int>> uniquepairs;
    for (int i = 0;i < pairs.size();i++) {
        if (!isTherePair(uniquepairs, pairs[i])) uniquepairs.push_back(pairs[i]);
    }
    return uniquepairs;
}
std::vector<std::vector<int>> newClasses(std::vector<std::vector<int>>& classes, std::vector<std::pair<int, int>>& pairs) {
    std::vector<std::vector<int>> Newclasses;

   
    for (int i = 0;i < classes.size();i++) {
        if (classes[i].size() == 1) {
            Newclasses.push_back({ classes[i] });
           
            continue;
        }
      
        std::vector<std::pair<int, int>> currPairs(classes[i].size());
        for (int j = 0;j < currPairs.size();j++) {
            currPairs[j] = pairs[classes[i][j] - 1];
         
        }
       

        std::vector<std::pair<int, int>> uniquepairs = uniquePairs(currPairs);
  

        if (uniquepairs.size() == currPairs.size()) {
           
            std::vector<int> helper;
            for (int j = 0;j < currPairs.size();j++) {
                
                Newclasses.push_back({ classes[i][j] });
               
            }
            
          
            continue;
        }
    
        for (int k = 0;k < uniquepairs.size();k++) {
            
            std::vector<int> helper;
            for (int j = 0;j < currPairs.size();j++) {

                if (currPairs[j] == uniquepairs[k]) {
                    helper.push_back(classes[i][j]);
                }
            }
           
            Newclasses.push_back(helper);
            
        }

    }
    
    return Newclasses;
}
bool someStateisFinal(std::vector<int> vec, std::vector<State*>& states) {
    
    for (int i = 0;i < vec.size();i++) {
        if (states[vec[i] - 1]->isFinal) return true;
    }
    return false;
}
//MINIMIZATION
void minimization(std::vector<State*>& states) {
  
    std::vector<std::pair<int, int>> MainPairs(states.size());
    for (int j = 0;j < states.size();j++) {
        MainPairs[j].first = states[j]->transitionA.second[0]->ID;
        MainPairs[j].second = states[j]->transitionB.second[0]->ID;
      
    }



    std::vector<std::vector<int>> classes(2);
    for (int i = 0;i < states.size();i++) {
        if (states[i]->isFinal) classes[0].push_back(states[i]->ID);
        else classes[1].push_back(states[i]->ID);
    }
    std::vector<std::pair<int, int>> pairsCurrentClasses(states.size());
    pairsOfClasses(classes, pairsCurrentClasses, MainPairs);
    classes = newClasses(classes, pairsCurrentClasses);

    while (true) {
    
        int size = classes.size();
        pairsOfClasses(classes, pairsCurrentClasses, MainPairs);
        classes = newClasses(classes, pairsCurrentClasses);
        int newSize = classes.size();
        if (size == newSize) break;
    }
    pairsOfClasses(classes, pairsCurrentClasses, MainPairs);
 /*   for (int j = 0;j < classes.size();j++) {
        for (int i = 0;i < classes[j].size();i++) {

            std::cout << classes[j][i] << ' ';
        }
        std::cout << '\n';

    }*/

    std::vector<State*> minimizedStates(classes.size());
    for (int y = 0;y < classes.size();y++) {
        minimizedStates[y] = new State();
        minimizedStates[y]->ID = y + 1;
        if (someStateisFinal(classes[y], states)) {
            minimizedStates[y]->isFinal = true;
            
        }
      
    }
    std::cout << "--------------------------------------------------" << '\n';
    std::cout << "Minimization" << '\n';
    for (int y = 0;y < classes.size();y++) {
        minimizedStates[y]->transitionA.second = {minimizedStates[pairsCurrentClasses[y].first - 1]};
        minimizedStates[y]->transitionB.second = { minimizedStates[pairsCurrentClasses[y].second - 1]};
        minimizedStates[y]->print();
    }
    states =  minimizedStates;

}

void fromNFAtoMTDFA(std::vector<State*>& states) {
    State emptySet;
    createEmptySet(emptySet);
    Totalization(states, emptySet);
    determinization(states);
    minimization(states);
    std::cout << '\n';
    std::cout << "Final Minimized totalized determinizised Automat: " << '\n';
    for (int i = 0;i < states.size();i++) {
        states[i]->print();
    }
}

int main()
{

    
    State A;
    State B;
    State C;
    State D;
    A.isFinal = true;
    /*  State Null;
      State* np = nullptr;

      Null.addTransition('a', np);
      Null.addTransition('b', np);*/
    State* ptr2 = &D;
    State* ptr = &A;
    State* ptr3 = &B;
    B.addTransition('a', ptr);
    A.isStart = true;
    State* ptr1 = &C;
 
    B.addTransition('a', ptr1);

    B.addTransition('a', ptr1);
    B.addTransition('b', ptr2);


    C.addTransition('a', ptr1);
    C.addTransition('b', ptr2);

    A.addTransition('a', ptr1);
    A.addTransition('b', ptr3);

   
   


    D.addTransition('a', ptr);
 
    
    std::vector<State*> vec = { &A, &B, &C, &D };


    fromNFAtoMTDFA(vec);
   /* std::vector<State*> vec1 = { &A, &B, &emptySet, &emptySet };
    unique(vec1);
    std::cout << vec1.size();*/


   
    /* std::vector<State*> vec1 = { &B, &A};
     std::vector<State*> vec2 = {&A, &B};
     vectorsMerged(vec1, vec2);*/
 /*   Totalization(vec, emptySet);
    for (int i = 0;i < vec.size();i++) {
        vec[i]->print();
    }*/

    /*   sortStates(vec1);
       sortStates(vec2);
       std::cout << areTheSame(vec1, vec2);*/
       /*   sortStates(vec1);
          for (int i = 0;i < vec1.size();i++) {
              vec1[i]->print();
          }*/
    //std::cout << "-------------------------------------" << '\n';
    //determinization(vec);
    //std::cout << "-------------------------------------" << '\n';
  //  minimization(vec);
 //   fromNFAtoMTDFA(vec);
   /* std::vector<std::vector<int>> classes;
    classes.push_back({ 1, 2});
    classes.push_back({ 3, 4});
    

    std::vector<std::pair<int, int>> pairs;
    pairs.push_back({ 1, 1});
    pairs.push_back({ 1, 2});
    pairs.push_back({ 2, 1});
    pairs.push_back({ 2, 1 });
    std::vector<std::vector<int>> Newclasses = newClasses(classes, pairs);*/


    //minimization(vec);



/*  curr = { states[0] };
  q.push(curr);

  while (true) {
      if (q.empty()) {
          break;
      }
      curr = q.front();
      std::vector<State*> startA;
      std::vector<State*> startB;
      for (int j = 0;j < curr.size();j++) {
          vectorsMerged(startA, curr[j]->transitionA.second);
          vectorsMerged(startB, curr[j]->transitionA.second);
      }
      if (!SubsetIsThere(q, startA)) {
          q.push(startA);
      }
      if (!SubsetIsThere(q, startB)) {
          q.push(startB);
      }
      q.pop();

      int idxCurr = idx(finalStates, curr);
      int idxA = idx(finalStates, startA);
      int idxB = idx(finalStates, startB);

      finals[idxCurr]->transitionA.second = { finals[idxA] };
      finals[idxCurr]->transitionB.second = { finals[idxB] };

  }*/


  //   return finals;

   }
