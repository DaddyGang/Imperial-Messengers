## Visual Concepts Programming Challenge - "Imperial Messengers"

### Compilation
gcc source.c -o app.exe

### Time Chart

- 7:56 pm : Started reading the problem
- 8:42 pm : Finished coding and testing
- Then I took a shower
- 9:02 pm : Started to write some comments
- 9:28 pm : Googled for optimization
- 9:43 pm : Started to write documentation
- 10:18 pm : Finished writing documentation

### Ideas
> Return the largest of all shortest distances from the capitol to any of the empire's cities.

Upon reading the problem, I felt like this is a standard "Single-source Shortest-path" problem, which I recall can be solved by Dijkstra's or Bellman-Ford Algorithm. I wounded up using Bellman-Ford because I feel like it is straight-forward and easy to implement - you just relax all edges for at most V-1 iterations. And since a distance between two cities cannot be negative, we don't need to consider negative weights at all.

### Frank words

- I did spend more time dealing with environment and input caveats than coding the algorithm itself. Visual Studio feels clucky for standard-C. So I compiled my file using command line gcc.
- I googled for optimization for Bellman-Ford, one simple optimization was to break early when there is no shorter edge included in one iteration. The other improved algorithm named SPFA uses queue to reduce redundant calculation. But it means I would need to implement linked-list in standard C for myself. So I decided not to go for it, though I can if I have more time.
