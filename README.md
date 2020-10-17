# Competetive-Code-Backup
This repo includes the code that I must remember at all times when I encounter a problem
<ol>
  <li>Large Array can be declared globally</li>
  <li>
    Copy by reference + Global Declarations reduces running time
  </li>
  <li>
    Avoid <b>endl</b>, it increases runnning time. https://stackoverflow.com/questions/213907/stdendl-vs-n
   </li>
  <li>Bitsets may be highly useful in reducing complexities
    <br>
    <u>Example:</u>
    https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/utkarsh-in-gardens-february-easy/description/
  </li>
  <li>
    <b>Custom Lowerbound Function</b>
    :https://stackoverflow.com/questions/12968498/compare-function-in-lower-bound
  </li>
  <li>
    <b>Distinct Elements in range l to r using BIT:</b> https://www.geeksforgeeks.org/queries-number-distinct-elements-subarray/<br>  
  </li>
  <li>
    Important DPs:
    <ul>
      <li>
        https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/number-of-rs-1/<br><strong>How to detect the application of Maximum Subarray Problem:</strong>For a range from 1 to n, at some point i we check ans=max(maxSubArraySum(1...i),maxSubArraySum(i+1...n),maxSumPassingThroughi) which is seen in divide and conquer equivalent of Maximum Subarray Problem<br><br>
      </li>
      <li>
        <b>
          Partion such that two subsets have minimum difference:
        </b> https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/amazing-test/<br><br>
      </li>
      <li>
        https://www.codechef.com/problems/SPAR3<br><br>
      </li>
      <li>
        <b>
          Important 3d dp: 
        </b>
        https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/shift-the-array-4074fac2/description/
        <br>Approrach the question using 26^n and then see how to memoize<br><br>
      </li>
      <li>
          <b>
            Algorithm for finding minimum cycle length in unweighted graph(use bfs and approach below for unweighted undirected graph ) - Complexity O(e^2) [So far minimum complexity for finding min cycle length I have seen]
          </b>
          https://www.geeksforgeeks.org/find-minimum-weight-cycle-undirected-graph/
       </li>
    <li>
      <b>Gray Codes differ by one bit in each successive step</b>
    </li>
     <li>
       <strong> Method to generate subsets of a a number in binary-></strong> <br>
       Let the number be x and tmp = x, then we can successively compute tmp=(tmp-1)&x, tmp will be the subset -> stop at 0<br>Example let x = 13, and thus tmp = 13,  now : <br>
      ->First Subset : 13
       <br>->Second Subbset : (13-1)&13 = 12
       <br> ->Third Subset: (12-1)&13 = 9
       <br> ->Fourth Subset: (9-1)&13 = 8
       <br> ->Fifth Subset: (8-1)&13 = 5
       <br> ->Sixth Subset: (5-1)%13  = 4
       <br> ->Seventh Subset: (4-1)%13 = 1
       <br> ->Eighth Subset: (1-0)&13 = 0
       <br><b> Reference:</b> Inner loop of suboptimal solution section on https://codeforces.com/blog/entry/45223
       </li>
    
   </ul>
  </li>
</ol>
