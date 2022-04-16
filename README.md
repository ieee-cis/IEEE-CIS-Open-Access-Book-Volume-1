# IEEE-CIS-Open-Access-Book-Volume-1
Open access book with an introduction to Computational Intelligence.

The first edition covers Search-Based Optimization and Learning Systems. The second edition is planned to also cover Fuzzy Systems.

# License

By submitting to this repository you agree with the terms and conditions of the license at [license.txt](license.txt).

# Instructions for Adding Your Chapter

Each chapter is within a folder, where Part 2 contains the search-based optimisation chapters and Part 3 contains the learning systems chapters.

Please make alterations only the folder corresponding to your chapter, except for (1) below.

1. When adding packages, add them to the file main.tex.


2. The header of the chapter should have as in the current template:

\title{Title}  
\label{chp:label} % don't change the label currently inserted in your chapter .tex
\author{} % add the list of authors
\institute{} % add the institutions of the authors
\maketitle

3. The end of the chapter should have the following, as in the current template:

\bibliographystyle{unsrt}

\bibliography{bibliography}

4. Your bibliography should be within the file named bibliography.bib


# Compilation Instructions

1. pdflatex main.tex
2. Go to the folder with your chapter
3. bibtex your chapter and return to the main folder
4. pdflatex main.tex
5. pdflatex main.tex

