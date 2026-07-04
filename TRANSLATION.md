# Vietnamese Translation

This fork translates **OI Wiki** into Vietnamese while keeping the upstream
MkDocs source layout intact.

## Current Scope

- `README.md`: translated and annotated for this fork.
- `CODE_OF_CONDUCT.md`, `scripts/README.md`, `patches/README.md`,
  `mkdocs.yml`: translated root project metadata, tooling notes, patch notes,
  and rendered copyright conjunctions.
- `scripts/*.py`, `scripts/post-build/commits-info/task-handler.ts`, and
  `docs/geometry/images/andrew.py`: translated user-facing CI summaries,
  generated commit-info fallback strings, celebration issue text, and Andrew
  convex-hull diagram labels.
- `docs/basic/images/divide-and-conquer-*.svg` and
  `docs/ds/images/kuaizhuanglianbiao.svg`: replaced referenced raster diagrams
  with editable Vietnamese SVG versions.
- `docs/index.md`: translated landing page.
- `docs/edit-landing.md`: translated the in-browser edit landing prompt.
- `docs/intro/about.md`: translated project overview.
- `docs/contest/index.md`, `docs/lang/index.md`, `docs/basic/index.md`:
  translated section introductions.
- `docs/intro/what-oi-wiki-is-not.md`, `docs/intro/mirrors.md`,
  `docs/intro/thanks.md`: translated project policy and metadata pages.
- `docs/contest/problems.md`, `docs/contest/icpc.md`,
  `docs/contest/io.md`, `docs/contest/dictionary.md`,
  `docs/contest/common-tricks.md`: translated contest overview and technique
  pages.
- `docs/basic/complexity.md`, `docs/basic/amortized-analysis.md`,
  `docs/basic/enumerate.md`, `docs/basic/simulate.md`: translated basic
  algorithm foundation pages.
- `docs/basic/binary-lifting.md`, `docs/basic/construction.md`,
  `docs/basic/sort-intro.md`, `docs/basic/selection-sort.md`,
  `docs/basic/bubble-sort.md`, `docs/basic/insertion-sort.md`,
  `docs/basic/counting-sort.md`, `docs/basic/use-of-sort.md`: translated
  additional basic algorithm and sorting pages.
- `docs/basic/greedy.md`, `docs/basic/bucket-sort.md`,
  `docs/basic/heap-sort.md`, `docs/basic/tim-sort.md`,
  `docs/basic/tournament-sort.md`, `docs/basic/merge-sort.md`,
  `docs/basic/radix-sort.md`, `docs/basic/stl-sort.md`: translated more basic
  greedy and sorting pages.
- `docs/basic/divide-and-conquer.md`, `docs/basic/binary.md`,
  `docs/basic/prefix-sum.md`, `docs/basic/quick-sort.md`,
  `docs/basic/shell-sort.md`: translated the remaining medium-sized basic
  algorithm and sorting pages.
- `docs/contest/resources.md`, `docs/contest/roadmap.md`: translated learning
  resources and roadmap pages.
- `docs/intro/htc.md`, `docs/intro/faq.md`, `docs/intro/format.md`:
  translated contributor guide, FAQ, and formatting manual, while preserving
  compatibility anchors for existing upstream links.
- `docs/contest/oi.md`, `docs/contest/common-mistakes.md`,
  `docs/intro/docker-deploy.md`, `docs/intro/symbol.md`: translated OI contest
  formats, common contest mistakes, Docker deployment instructions, and the
  mathematical symbol reference.
- `docs/contest/interaction.md`, `docs/contest/problemsetting.md`: translated
  the remaining contest pages on interactive problems and problem setting.
- `docs/lang/helloworld.md`, `docs/lang/struct.md`, `docs/lang/union.md`:
  translated the first beginner C++ language pages.
- `docs/lang/array.md`, `docs/lang/branch.md`, `docs/lang/loop.md`:
  translated beginner C++ array and control-flow pages.
- `docs/lang/basic.md`, `docs/lang/func.md`, `docs/lang/file-op.md`:
  translated beginner C++ syntax, function, and file-operation pages.
- `docs/lang/var.md`, `docs/lang/op.md`, `docs/lang/pointer.md`: translated
  beginner C++ variable, operator, and pointer pages.
- `docs/lang/namespace.md`, `docs/lang/reference.md`, `docs/lang/const.md`:
  translated C++ namespace, reference, and const/constexpr pages.
- `docs/lang/class.md`, `docs/lang/value-category.md`,
  `docs/lang/op-overload.md`: translated C++ class, value-category, and operator
  overloading pages.
- `docs/lang/new.md`, `docs/lang/lambda.md`,
  `docs/lang/cpp-other-langs.md`: translated modern C++ features, lambda
  expressions, and comparisons between C++ and other common languages.
- `docs/lang/pb-ds/index.md`, `docs/lang/pb-ds/pq.md`,
  `docs/lang/pb-ds/tree.md`, `docs/lang/optimizations.md`,
  `docs/lang/pas-cpp.md`: translated GNU pb_ds, compiler optimization, and
  Pascal-to-C++ transition pages.
- `docs/lang/python.md`, `docs/lang/java.md`, `docs/lang/java-pro.md`:
  translated Python and Java quick-start/advanced language pages.
- `docs/lang/csl/*.md`: translated the C++ standard-library/STL overview,
  container, iterator, algorithm, bitset, string, and pair pages.
- `docs/search/*.md`: translated the search algorithm pages, including DFS,
  BFS, bidirectional search, heuristic search, A*/IDA*, iterative deepening,
  backtracking, Dancing Links, Alpha-Beta pruning, and search optimization.
- `docs/dp/basic.md`, `docs/dp/memo.md`, `docs/dp/knapsack.md`,
  `docs/dp/interval.md`, `docs/dp/dag.md`, `docs/dp/tree.md`,
  `docs/dp/state.md`, `docs/dp/number.md`, `docs/dp/count.md`,
  `docs/dp/dynamic.md`, `docs/dp/probability.md`,
  `docs/dp/dp-of-dp.md`: translated the core dynamic-programming pages and
  explanatory code comments in their included snippets.
- `docs/dp/plug.md`, `docs/dp/opt/dp-opt.md`,
  `docs/dp/opt/monotonic-queue-stack.md`, `docs/dp/opt/slope.md`,
  `docs/dp/opt/quadrangle.md`, `docs/dp/opt/slope-trick.md`,
  `docs/dp/opt/state.md`, `docs/dp/opt/wqs-binary-search.md`: translated
  plug DP and DP optimization pages, plus explanatory comments in their
  included snippets; quality-passed the Slope Trick introduction, convex
  function definitions, slope/epigraph characterizations, and convex
  transformation material, plus the opening kink-maintenance section and
  Sequence/Safety examples, and the slope-maintenance stock/Landscaping examples
  and closing notes in
  `docs/dp/opt/slope-trick.md`.
- `docs/string/basic.md`, `docs/string/lib-func.md`,
  `docs/string/match.md`: translated the introductory string material covering
  alphabets, substrings, C/C++ string helpers, and baseline string matching
  algorithms.
- `docs/string/hash.md`, `docs/string/trie.md`, `docs/string/kmp.md`,
  `docs/string/z-func.md`, `docs/string/ac-automaton.md`: translated core
  string hashing, trie, prefix-function/KMP, Z-function, and AC automaton
  material, plus explanatory comments in their included snippets.
- `docs/string/bm.md`, `docs/string/sa.md`,
  `docs/string/sa-optimal-inplace.md`, `docs/string/suffix-bst.md`,
  `docs/string/general-sam.md`, `docs/string/suffix-tree.md`,
  `docs/string/seq-automaton.md`, `docs/string/minimal-string.md`,
  `docs/string/lyndon.md`, `docs/string/main-lorentz.md`: translated
  Boyer-Moore, suffix-array and suffix-structure pages, sequence automata,
  minimal representation, Lyndon decomposition, and Main-Lorentz material,
  plus explanatory comments in their included snippets.
- `docs/string/sam.md`, `docs/string/manacher.md`, `docs/string/pam.md`:
  translated the remaining suffix automaton, Manacher, and palindromic-tree
  pages, plus explanatory comments in the palindromic-tree snippets.
- `docs/math/numeral-sys/intro.md`, `docs/math/numeral-sys/base.md`,
  `docs/math/numeral-sys/balanced-ternary.md`,
  `docs/math/numeral-sys/gray-code.md`, `docs/math/bit.md`,
  `docs/math/binary-exponentiation.md`: translated numeral-system basics, bit
  operations, and binary exponentiation, plus explanatory comments in included
  snippets.
- `docs/math/boolean-algebra.md`, `docs/math/binary-set.md`,
  `docs/math/permutation.md`, `docs/math/coordinate.md`,
  `docs/math/complex.md`: translated general math pages on Boolean algebra,
  binary set operations, permutations, coordinate systems, and complex numbers,
  plus explanatory comments in permutation snippets.
- `docs/math/bignum.md`, `docs/math/number-theory/basic.md`,
  `docs/math/number-theory/mod-arithmetic.md`,
  `docs/math/number-theory/prime.md`, `docs/math/number-theory/gcd.md`,
  `docs/math/number-theory/euler-totient.md`,
  `docs/math/number-theory/sieve.md`, `docs/math/number-theory/inverse.md`,
  `docs/math/number-theory/linear-equation.md`: translated arbitrary-precision
  arithmetic and the first number-theory pages, plus explanatory comments in
  the included modular arithmetic, prime, inverse, and linear congruence
  snippets.
- Quality pass: restored Vietnamese diacritics and smoothed core prose in
  selected `docs/math/number-theory/basic.md`,
  `docs/math/number-theory/mod-arithmetic.md`, and
  `docs/math/number-theory/prime.md` sections, including the Miller-Rabin
  algorithm outline, reference implementation comments, and probability proof,
  deterministic-base notes, anti-prime introduction, examples, and references,
  then fully cleaned
  `docs/math/number-theory/basic.md`,
  `docs/math/number-theory/mod-arithmetic.md`,
  `docs/math/number-theory/gcd.md` and
  `docs/math/number-theory/sieve.md`, cleaned remaining exercise titles in
  `docs/math/number-theory/euclidean.md`, plus the opening concept sections of
  `docs/math/number-theory/quadratic.md` through the Eisenstein integer
  material.
- `docs/math/number-theory/pollard-rho.md`,
  `docs/math/number-theory/bezouts.md`,
  `docs/math/number-theory/fermat.md`, `docs/math/number-theory/crt.md`,
  `docs/math/number-theory/lift-the-exponent.md`,
  `docs/math/number-theory/factorial.md`,
  `docs/math/number-theory/lucas.md`,
  `docs/math/number-theory/congruence-equation.md`,
  `docs/math/number-theory/quad-residue.md`: translated factorization, Bézout,
  Fermat/Euler, CRT, LTE, factorial modulo, Lucas, congruence-equation, and
  quadratic-residue material, plus explanatory comments in included snippets.
- `docs/math/number-theory/primitive-root.md`,
  `docs/math/number-theory/discrete-logarithm.md`,
  `docs/math/number-theory/residue.md`,
  `docs/math/number-theory/sqrt-decomposition.md`: translated primitive-root,
  discrete-logarithm, higher-residue/unit-root, and number-theory block
  decomposition material, plus explanatory comments in included snippets;
  quality-passed `docs/math/number-theory/primitive-root.md` through the
  Carmichael-number section and footnotes, and the opening high-order-residue
  and unit-root sections of `docs/math/number-theory/residue.md`, plus its
  direct modular-root algorithm, improved Tonelli-Shanks derivation and
  complexity analysis, general-case handling, and footnotes.
- `docs/math/number-theory/dirichlet.md`,
  `docs/math/number-theory/mobius.md`, `docs/math/number-theory/du.md`,
  `docs/math/number-theory/powerful-number.md`,
  `docs/math/number-theory/min-25.md`, `docs/math/number-theory/zhou.md`,
  `docs/math/number-theory/meissel-lehmer.md`: translated multiplicative
  function, Möbius inversion, Dujiao/Powerful Number/Min_25/Zhouge sieve, and
  Meissel-Lehmer prime-counting material, plus explanatory comments in included
  snippets.
- `docs/math/number-theory/euclidean.md`,
  `docs/math/number-theory/continued-fraction.md`,
  `docs/math/number-theory/stern-brocot.md`,
  `docs/math/number-theory/quadratic.md`,
  `docs/math/number-theory/pell-equation.md`: translated the remaining
  number-theory tail covering Euclidean-like algorithms, continued fractions,
  Stern-Brocot/Farey structures, quadratic fields, and Pell equations, plus
  explanatory comments in included Stern-Brocot snippets; quality-passed the
  opening solution-structure discussion, first Pell solution-structure
  theorem/existence proof and nontrivial-solution proof, generalized-Pell
  equivalence-class structure, the PQa theorem block and Pell-solving
  derivation/examples, the negative-Pell theorem around the missing quadratic
  factor, the negative-Pell solubility proof, the opening norm-±4 reduction and
  Legendre criterion, the norm-±4 continued-fraction facts,
  solution-structure theorem, parity theorem, and fundamental-unit corollary,
  plus the norm-±4 and generalized-Pell examples, and the general
  Lagrange–Matthews–Mollin argument in
  `docs/math/number-theory/pell-equation.md`, including its LMM examples and
  closing notes.
- `docs/math/poly/intro.md`, `docs/math/poly/fundamental.md`,
  `docs/math/poly/fft.md`, `docs/math/poly/ntt.md`,
  `docs/math/poly/fwt.md`, `docs/math/poly/czt.md`: translated the opening
  polynomial/generating-function pages and Fourier/number-theoretic/Walsh/Chirp
  Z transform material, plus explanatory comments in included FFT and CZT
  snippets.
- `docs/math/poly/newton.md`,
  `docs/math/poly/multipoint-eval-interpolation.md`,
  `docs/math/poly/elementary-func.md`,
  `docs/math/poly/linear-recurrence.md`, `docs/math/poly/shift.md`,
  `docs/math/poly/symbolic-method.md`,
  `docs/math/poly/lagrange-inversion.md`, `docs/math/poly/comp-rev.md`,
  `docs/math/poly/ogf.md`, `docs/math/poly/egf.md`: translated the remaining
  polynomial and generating-function pages, plus explanatory comments in
  included polynomial square-root and composition snippets.
- `docs/math/combinatorics/*.md`: translated the combinatorics section covering
  basic counting, inclusion-exclusion, Fibonacci/Catalan/Stirling/Bell/Bernoulli
  numbers, partitions, Vandermonde convolution, Pólya counting, and graph
  enumeration, plus explanatory comments in included combinatorics snippets.
- `docs/math/linear-algebra/*.md`, `docs/math/linear-programming.md`,
  `docs/math/simplex.md`: translated linear algebra and linear programming
  material, plus explanatory comments in included linear-basis and simplex
  snippets.
- `docs/math/algebra/*.md`: translated abstract algebra material covering
  basic concepts, group/ring/field theory, Schreier-Sims, and explanatory
  comments in the Schreier-Sims snippet.
- `docs/math/probability/*.md`: translated probability basics, conditional
  probability and independence, random variables, expectation/variance, and
  concentration inequalities.
- `docs/math/game-theory/*.md`: translated game-theory overview, impartial
  combinatorial games, zero-sum games, and explanatory comments in included
  game-theory snippets; the upstream partizan-game page is currently empty.
- `docs/math/numerical/*.md`: translated numerical algorithms covering
  interpolation, numerical integration, Gaussian elimination, and Newton's
  method, plus explanatory comments in included interpolation snippets.
- `docs/math/order-theory.md`, `docs/math/young-tableau.md`,
  `docs/math/matroid.md`, `docs/math/berlekamp-massey.md`: translated the
  remaining standalone math pages on order theory, Young tableaux, matroids,
  and Berlekamp-Massey, plus explanatory comments in order-theory snippets.
- `docs/ds/stack.md`, `docs/ds/queue.md`, `docs/ds/linked-list.md`,
  `docs/ds/hash.md`: translated the opening data-structure pages covering
  stacks, queues/deques, linked lists, and hash tables, plus explanatory
  comments in included queue snippets.
- `docs/ds/dsu.md`, `docs/ds/dsu-complexity.md`: translated the union-find/DSU
  pages covering core operations, extensions, examples, and the amortized
  complexity proof, plus explanatory comments in included DSU snippets.
- `docs/ds/heap.md`, `docs/ds/binary-heap.md`,
  `docs/ds/pairing-heap.md`, `docs/ds/leftist-tree.md`: translated heap
  overview, binary heap, pairing heap, and leftist tree material, plus
  explanatory comments in included heap snippets.
- `docs/ds/decompose.md`, `docs/ds/block-array.md`,
  `docs/ds/block-list.md`, `docs/ds/tree-decompose.md`,
  `docs/ds/sqrt-tree.md`: translated block-based data-structure material
  covering sqrt decomposition, block arrays/lists, tree decomposition, and
  Sqrt Tree, plus explanatory comments in included snippets.
- `docs/ds/monotonic-stack.md`, `docs/ds/monotonic-queue.md`,
  `docs/ds/sparse-table.md`, `docs/ds/dividing.md`: translated short
  range-query data-structure pages covering monotonic stack/queue, Sparse
  Table, and dividing tree, plus explanatory comments in included snippets.
- `docs/ds/fenwick.md`: translated the Fenwick tree page covering one- and
  two-dimensional BIT operations, range-add/range-sum transformations, value
  Fenwick applications, non-differentiable information, and implementation
  tricks.
- `docs/ds/seg-merge-split.md`, `docs/ds/li-chao-tree.md`,
  `docs/ds/cat-tree.md`, `docs/ds/seg-beats.md`,
  `docs/ds/kinetic-tournament-tree.md`: translated segment-tree subpages
  covering merge/split techniques, Li Chao trees, cat trees, Segment Tree
  Beats, historical extrema, and Kinetic Tournament Trees.
- `docs/ds/seg.md`: translated the foundational segment tree page covering
  construction, range queries, lazy propagation, dynamic opening nodes,
  templates, examples, extensions, and graph-building optimization, plus
  explanatory comments in included snippets.
- `docs/ds/cartesian-tree.md`, `docs/ds/avl.md`, `docs/ds/aa-tree.md`,
  `docs/ds/sgt.md`: translated smaller balanced-tree pages covering
  Cartesian trees, AVL trees, AA trees, and scapegoat trees.
- `docs/ds/sbt.md`: translated the Size Balanced Tree page covering node
  fields, balance invariants, rotations, insertion/deletion, rank queries, and
  the included map implementation reference.
- `docs/ds/bst.md`, `docs/ds/splay.md`, `docs/ds/rbtree.md`,
  `docs/ds/skiplist.md`: translated binary-search-tree and balanced-tree
  material covering BST operations, splay amortized analysis and operations,
  red-black tree insertion/deletion maintenance, and skip list complexity and
  implementation.
- `docs/ds/treap.md`, `docs/ds/wblt.md`, `docs/ds/llrbt.md`,
  `docs/ds/persistent.md`, `docs/ds/persistent-seg.md`: translated Treap,
  WBLT, left-leaning red-black tree, and persistent data-structure material,
  including rendered code comments for Treap and persistent segment tree
  examples.
- `docs/ds/persistent-balanced.md`, `docs/ds/persistent-trie.md`,
  `docs/ds/persistent-heap.md`: translated persistent balanced tree, Trie,
  and mergeable heap pages, plus rendered comments in the persistent Trie
  example.
- `docs/ds/seg-in-seg.md`, `docs/ds/balanced-in-seg.md`,
  `docs/ds/seg-in-bit.md`: translated tree-of-data-structures pages covering
  segment-tree nesting, segment-tree-with-balanced-tree operations, and
  Fenwick-tree-with-value-segment-tree dynamic ranking.
- `docs/ds/bit-in-block-array.md`, `docs/ds/kdt.md`,
  `docs/ds/global-bst.md`, `docs/ds/ett.md`: translated block-with-Fenwick,
  K-D Tree, global balanced binary tree, and Euler Tour Tree pages, including
  rendered comments in the Euler Tour Tree example.
- `docs/ds/divide-combine.md`, `docs/ds/pq-tree.md`,
  `docs/ds/finger-tree.md`, `docs/ds/huffman-tree.md`: translated
  miscellaneous data-structure pages covering divide-combine trees, PQ trees,
  finger trees, and Huffman trees, including rendered comments and output
  strings in the Huffman examples.
- `docs/ds/lct.md`, `docs/ds/top-tree.md`: translated dynamic-tree pages
  covering Link/Cut Tree and Self-Adjusting Top Tree.
- `docs/graph/concept.md`, `docs/graph/save.md`, `docs/graph/dfs.md`,
  `docs/graph/bfs.md`: translated foundational graph-theory pages covering
  graph terminology, graph storage formats, DFS, and BFS, including pseudocode
  and rendered code comments.
- `docs/graph/tree-basic.md`, `docs/graph/tree-diameter.md`,
  `docs/graph/tree-center.md`, `docs/graph/tree-centroid.md`,
  `docs/graph/lca.md`: translated the first tree-theory pages covering tree
  terminology, diameter, center, centroid, and LCA methods.
- `docs/graph/hld.md`, `docs/graph/dsu-on-tree.md`,
  `docs/graph/virtual-tree.md`, `docs/graph/tree-divide.md`: translated
  tree-technique pages covering HLD, DSU on tree, virtual trees, and tree
  divide/centroid decomposition.
- `docs/graph/dynamic-tree-divide.md`, `docs/graph/tree-ahu.md`,
  `docs/graph/tree-hash.md`, `docs/graph/tree-random-walk.md`: translated the
  remaining tree subsection pages covering dynamic centroid decomposition, AHU
  tree isomorphism, tree hashing, and random walks on trees.
- `docs/graph/dag.md`, `docs/graph/topo.md`,
  `docs/graph/shortest-path.md`, `docs/graph/diff-constraints.md`,
  `docs/graph/kth-path.md`, `docs/graph/mod-shortest-path.md`: translated DAG,
  topological sorting, shortest-path algorithms, difference constraints,
  k-shortest walks, and modular shortest-path material.
- `docs/graph/mst.md`, `docs/graph/dmst.md`, `docs/graph/mdst.md`,
  `docs/graph/steiner-tree.md`, `docs/graph/node.md`: translated spanning-tree
  algorithms, directed and minimum-diameter spanning trees, Steiner tree, and
  node-splitting graph modeling material.
- `docs/graph/scc.md`, `docs/graph/bcc.md`, `docs/graph/cut.md`,
  `docs/graph/block-forest.md`, `docs/graph/connectivity.md`: translated
  connectivity material covering SCCs, biconnected components, articulation
  points, bridges, block-cut trees, and vertex/edge connectivity.
- `docs/graph/rings-count.md`, `docs/graph/min-cycle.md`,
  `docs/graph/2-sat.md`, `docs/graph/euler.md`,
  `docs/graph/hamilton.md`, `docs/graph/bi-graph.md`: translated cycle
  counting, minimum cycle, 2-SAT, Euler/Hamilton graph, and bipartite graph
  material.
- `docs/graph/planar.md`, `docs/graph/chord.md`,
  `docs/graph/color.md`: translated planar graph, chordal graph, and graph
  coloring material.
- `docs/graph/flow.md`, `docs/graph/flow/max-flow.md`,
  `docs/graph/flow/min-cut.md`, `docs/graph/flow/min-cost.md`,
  `docs/graph/flow/bound.md`, `docs/graph/stoer-wagner.md`: translated
  network-flow overview, max flow, min cut, min-cost flow, bounded flows, and
  Stoer-Wagner global min-cut material.
- `docs/graph/graph-matching/graph-match.md`,
  `docs/graph/graph-matching/bigraph-match.md`,
  `docs/graph/graph-matching/bigraph-weight-match.md`,
  `docs/graph/graph-matching/general-match.md`,
  `docs/graph/graph-matching/general-weight-match.md`,
  `docs/graph/graph-matching/stable-match.md`: translated graph matching,
  bipartite/general matching, weighted matching, and stable matching material.
- `docs/graph/prufer.md`, `docs/graph/matrix-tree.md`,
  `docs/graph/lgv.md`, `docs/graph/max-clique.md`,
  `docs/graph/dominator-tree.md`, `docs/graph/graph-random-walk.md`:
  translated Prüfer sequence, Matrix-Tree theorem, LGV lemma, maximum clique,
  dominator tree, and graph random-walk material.
- `docs/geometry/2d.md`, `docs/geometry/3d.md`,
  `docs/geometry/distance.md`, `docs/geometry/pick.md`,
  `docs/geometry/triangulation.md`, `docs/geometry/convex-hull.md`,
  `docs/geometry/scanning.md`, `docs/geometry/rotating-calipers.md`,
  `docs/geometry/half-plane.md`, `docs/geometry/nearest-points.md`,
  `docs/geometry/random-incremental.md`, `docs/geometry/inverse.md`,
  `docs/geometry/index.md`, `docs/geometry/misc.md`: translated
  computational geometry foundations and algorithm material.
- `docs/misc/discrete.md`, `docs/misc/two-pointer.md`,
  `docs/misc/offline.md`, `docs/misc/cdq-divide.md`,
  `docs/misc/parallel-binsearch.md`: translated discretization, two-pointer,
  offline algorithm, CDQ divide-and-conquer, and overall binary search
  material.
- `docs/misc/mo-algo-intro.md`, `docs/misc/mo-algo.md`,
  `docs/misc/modifiable-mo-algo.md`, `docs/misc/mo-algo-on-tree.md`,
  `docs/misc/rollback-mo-algo.md`, `docs/misc/mo-algo-2dimen.md`,
  `docs/misc/mo-algo-secondary-offline.md`,
  `docs/misc/mo-algo-with-bitset.md`: translated Mo's algorithm and its
  modification, tree, rollback, two-dimensional, secondary-offline, and bitset
  variants.
- `docs/misc/random.md`, `docs/misc/rand-technique.md`,
  `docs/misc/hill-climbing.md`, `docs/misc/simulated-annealing.md`:
  translated random number generation, randomized techniques, hill climbing,
  and simulated annealing material.
- `docs/misc/frac-programming.md`, `docs/misc/hoverline.md`,
  `docs/misc/endianness.md`, `docs/misc/josephus.md`,
  `docs/misc/job-order.md`, `docs/misc/main-element.md`,
  `docs/misc/garsia-wachs.md`, `docs/misc/15-puzzle.md`,
  `docs/misc/kahan-summation.md`, `docs/misc/space-optimization.md`:
  translated standalone miscellaneous algorithm and implementation notes.
- `docs/misc/fsm.md`, `docs/misc/cc-basic.md`,
  `docs/misc/expression.md`, `docs/misc/odt.md`: translated finite-state
  automata, computation theory basics, expression evaluation, and Chtholly
  Tree material.
- `docs/misc/code/*`: translated the remaining explanatory comments in
  miscellaneous algorithm snippets, including CDQ divide-and-conquer, Mo's
  algorithm variants, hill climbing, simulated annealing, fractional
  programming, majority element, DSU space optimization, and two-pointer cycle
  detection examples.
- `docs/**/images/*.tex` and `docs/**/images/*.typ`: translated visible labels
  and explanatory source comments in the first text-based diagram source batch,
  covering loop flowcharts, prefix sums, tree terminology, virtual trees, DSU
  compression, Splay rotations, Huffman coding, Top Tree, block decomposition,
  half-plane intersection, n-dimensional sqrt decomposition, and KMP prefix
  function diagrams.
- `docs/**/images/*.svg`: translated visible text labels and safe metadata in
  the remaining text-based SVG diagrams, including Fenwick query, topological
  prerequisite, complex-number set, Young tableau, finite-state-machine, Poker,
  and segment-tree diagram sources.
- `docs/topic/rmq.md`, `docs/topic/dsu-app.md`, `docs/topic/bracket.md`,
  `docs/topic/segment-tree-offline.md`: translated topic pages for RMQ, DSU
  applications, bracket sequences, and segment-tree divide-and-conquer over
  offline queries.
- `docs/tools/testlib/index.md`, `docs/tools/testlib/general.md`: translated
  the Testlib introduction and common API material.
- `docs/tools/testlib/validator.md`, `docs/tools/testlib/interactor.md`:
  translated the Testlib validator and interactor pages.
- `docs/tools/testlib/generator.md`: translated the Testlib generator page,
  including sample-code comments.
- `docs/tools/testlib/checker.md`: translated the Testlib checker page,
  including explanatory sample-code comments.
- `docs/tools/judger/index.md`, `docs/tools/judger/cena.md`,
  `docs/tools/judger/ccr-plus.md`: translated the local judging-tool overview
  and short Cena/CCR Plus pages.
- `docs/tools/judger/lemon.md`: translated the Lemon judging-tool page.
- `docs/tools/judger/arbiter.md`: translated the Arbiter judging-tool guide.
- `docs/tools/index.md`, `docs/tools/oj-tool.md`: translated the tools
  overview and OJ tool roundup.
- `docs/tools/compiler.md`: translated the compiler/interpreter installation
  guide.
- `docs/tools/cmd.md`: translated the command-line usage guide.
- `docs/tools/compile-debug.md`: translated the command-line compile/debug
  guide.
- `docs/tools/git.md`: translated the Git configuration, branching, merge,
  remote, ssh, and GUI workflow guide.
- `docs/tools/latex.md`: translated the LaTeX beginner tutorial, including
  environment setup, document structure, text formatting, tables, and figures.
- `docs/tools/polygon.md`: translated the Polygon collaborative problemsetting
  guide.
- `docs/tools/special-judge.md`: translated the Special Judge writing guide
  for multiple OJ and judging tools.
- `docs/tools/wsl.md`: translated the Windows Subsystem for Linux installation,
  configuration, GUI, VS Code, and WSL2 upgrade guide.
- `docs/tools/editor/atom.md`, `docs/tools/editor/cpeditor.md`,
  `docs/tools/editor/eclipse.md`, `docs/tools/editor/geany.md`: translated
  small editor setup and overview pages.
- `docs/tools/editor/guide.md`, `docs/tools/editor/clion.md`: translated the
  GUIDE and CLion editor pages.
- `docs/tools/editor/codeblocks.md`, `docs/tools/editor/devcpp.md`: translated
  the Code::Blocks and Dev-C++ editor pages.
- `docs/tools/editor/npp.md`: translated the Notepad++ editor workflow page.
- `docs/tools/editor/kate.md`: translated the Kate editor features and LSP
  setup page.
- `docs/tools/editor/vscode.md`: translated the VS Code compile/run, debugging,
  clangd, and editing workflow page.
- `docs/tools/editor/vim.md`: translated the Vim editor introduction and
  command tutorial.
- `docs/tools/editor/emacs.md`: translated the Emacs introductory tutorial and
  configuration examples.
- `docs/tools/editor/sublime.md`: translated the Sublime Text installation,
  customization, editing, build/run, and workflow guide.
- `docs/tools/editor/xcode.md`: translated the Xcode setup, single-file C/C++
  workflow, and `bits/stdc++.h` compatibility notes.
- Residual cross-links and general reference labels in translated basic,
  contest, intro, language, DP, and graph pages were aligned with Vietnamese
  headings while preserving compatibility anchors and original problem names.
- Residual visible contest problem/resource labels were translated or normalized
  while preserving URLs, compatibility anchors, donor names, and official source
  identifiers.
- Official contest names and stage labels in `docs/contest/oi.md` were
  normalized into Vietnamese/romanized forms where needed.
- Chinese comments in `docs/basic/code` snippets were translated while keeping
  the example code unchanged.
- Chinese comments in translated contest I/O and data-structure code snippets
  were translated without changing the algorithms.
- Chinese comments in `docs/geometry/code` snippets were translated while
  preserving geometry implementations.
- Chinese comments in foundational `docs/graph/code` snippets covering 2-SAT,
  BFS, difference constraints, Euler paths, MST, modular shortest paths, Steiner
  trees, and tree centroids were translated.
- Chinese comments in structural graph/tree snippets covering BCC, block
  forests, cut vertices, DSU-on-tree, dynamic tree divide, HLD/LCA, tree AHU,
  and tree divide were translated.
- The remaining Chinese comments in `docs/graph/code` matching, max-clique,
  and MST snippets were translated, leaving graph code snippets free of Han
  characters.
- Section introductions for search, dynamic programming, strings, mathematics,
  data structures, graph theory, computational geometry, and miscellaneous
  topics are translated.
- `mkdocs.yml`: Vietnamese project metadata and translated top-level
  navigation labels for translated sections and pages.

The rest of `docs/` is intentionally left in the upstream structure and should
be translated page by page.

## Translation Conventions

- "competitive programming" -> "lập trình thi đấu"; optionally add
  "(competitive programming)" near the first occurrence.
- "Olympiad in Informatics" -> "Olympic Tin học" or "Olympiad Tin học" based
  on context.
- "algorithm" -> "thuật toán".
- "data structure" -> "cấu trúc dữ liệu".
- "graph" -> "đồ thị".
- "dynamic programming" -> "quy hoạch động"; use "DP" after the first clear
  occurrence when the source uses DP heavily.
- "string" -> "xâu" in algorithmic contexts; use "chuỗi" only when it reads
  more naturally for programming-language discussion.
- "range query" -> "truy vấn đoạn".
- "segment tree" -> "cây phân đoạn (segment tree)" on first occurrence, then
  "cây phân đoạn".
- "binary search" -> "tìm kiếm nhị phân" or "chặt nhị phân" depending on
  context; prefer "tìm kiếm nhị phân" in headings and beginner pages.
- "sweep line" -> "đường quét (sweep line)" on first occurrence.
- Keep names of contests, online judges, libraries, programming languages,
  commands, file paths, and code identifiers unchanged unless the surrounding
  prose explicitly explains them.
- Preserve formulas, asymptotic notation, examples, admonitions, links,
  frontmatter keys, and MkDocs extension syntax.
- Use English in parentheses sparingly for terms readers are likely to search
  for in editorials or documentation.

## Workflow

1. Translate in place under the original file path so upstream changes remain
   easy to merge.
2. Keep each commit focused on a small group of related pages.
3. Run `mkdocs build -v` after structural changes or pages that touch
   frontmatter, navigation, admonitions, math, tabs, or custom HTML.
4. Do not mechanically translate code comments inside examples unless they are
   part of the explanation and the code remains valid.
5. Prefer concise Vietnamese prose over word-for-word Chinese or English
   sentence structure.

## Build

```bash
pip install uv
uv sync
./scripts/pre-build/install-theme.sh
uv run mkdocs build -v
```

The theme installation step downloads upstream theme resources, so it requires
network access.
