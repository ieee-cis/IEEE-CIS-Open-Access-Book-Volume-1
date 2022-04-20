# IEEE-CIS-Open-Access-Book-Volume-1
Open access book with an introduction to Computational Intelligence.

The first edition covers Search-Based Optimization and Learning Systems. The second edition is planned to also cover Fuzzy Systems.

# License

By submitting to this repository you agree with the terms and conditions of the open license at [license.txt](license.txt).

# Instructions for Adding Your Chapter

Each chapter is within a folder, where Part 2 contains the search-based optimisation chapters and Part 3 contains the learning systems chapters.

Please make alterations only the folder corresponding to your chapter, except for (8) below.

1. Add the text content of your chapter to the corresponding file [chapter].tex, in the folder corresponding to your chapter.

2. The header of [chapter].tex should have the following as in the current template:

```    
	\title{Title}
	\label{chp:label} % don't change the label currently inserted in your chapter .tex
	\author{} % add the list of authors
	\institute{} % add the institutions of the authors
	\maketitle
```

3. No package should be added to the [chapter].tex file. No begin and end document should be added there either.

4. The end of the [chapter].tex file should have the following, as in the current template:

```
	\bibliographystyle{unsrt}
	\bibliography{bibliography}
```

5. Your bibliography should be within the file named bibliography.bib

6. Add all your packages to the [chapter] - Isolated.tex file in the folder corresponding to your chapter.

7. Compile the [chapter] - Isolated.tex file corresponding to your chapter with pdflatex and bibtex as you would normally do when creating a paper. This will allow you to create a separate pdf file for your chapter.

8. Add all your packages to the main.tex at the root folder of the book, if they are not already included there.

9. Compile the book following the instructions below. This will allow you to check whether your chapter is successfully included in the book.

# Compilation Instructions

1. pdflatex main.tex
2. Go to the folder with your chapter
3. bibtex your chapter and return to the main folder
4. pdflatex main.tex
5. pdflatex main.tex

