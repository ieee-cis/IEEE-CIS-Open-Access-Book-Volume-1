# IEEE-CIS-Open-Access-Book-Volume-1
Open access book with an introduction to Computational Intelligence.

The first edition covers Search-Based Optimization and Learning Systems. The second edition is planned to also cover Fuzzy Systems.

# License

By submitting to this repository you agree with the terms and conditions of the license at [license.txt](license.txt).

# Instructions for Adding Your Chapter

1. The header of the chapter should have:

\title{Title}  
\label{chp:label} % don't change the label currently inserted in your chapter .tex
\author{} % add the list of authors
\institute{} % add the institutions of the authors
\maketitle

2. The end of the chapter should have

\bibliographystyle{unsrt}

\bibliography{bibliography}

3. Your bibliography should be within the file named bibliography.bib

# Compilation Instructions

1. pdflatex main.tex
2. Go to the folder with your chapter
3. bibtex your chapter and return to the main folder
4. pdflatex main.tex
5. pdflatex main.tex

