# IEEE-CIS-Open-Access-Book-Volume-1
Open access book with an introduction to Computational Intelligence.

The first edition covers Search-Based Optimization and Learning Systems. The second edition is planned to also cover Fuzzy Systems.

# License

By submitting to this repository you agree with the terms and conditions of the open license at [license.txt](license.txt).

# Instructions for Adding Your Chapter

Each chapter is within a folder, where Part 2 contains the search-based optimisation chapters and Part 3 contains the learning systems chapters.

Please make alterations only the folder corresponding to your chapter, except for (10) below.

1. Add the text content of your chapter to the corresponding file [chapter].tex, in the folder corresponding to your chapter.

2. The paths to figures within your content should be the whole path from the main folder. For example, for the Naive Bayes chapter, one of the figures is included with the following command:

```
	Part 3 - Learning Systems/Supervised Learning/Naive Bayes/figures/nb-mass-function.png
```

3. The header of [chapter].tex should have the following as in the current template:

```    
	\title{Title}
	\label{chp:label} % don't change the label currently inserted in your chapter .tex
	\author{} % add the list of authors
	\institute{} % add the institutions of the authors
	\maketitle
```

4. No package should be added to the [chapter].tex file. No begin and end document should be added there either.

5. The end of the [chapter].tex file should have the following, as in the current template:

```
	\bibliographystyle{unsrt}
	\bibliography{bibliography}
```

6. Your bibliography should be within the file named bibliography.bib

7. Add all your packages to the [chapter] - Isolated.tex file in the folder corresponding to your chapter. Do not delete any other package that is already listed in that file.

8. Go to the folder corresponding to your chapter and run 

```
bibtex [chapter]
```

9. Return to the main folder and run

```
pdflatex [path to your chapter folder]/[chapter]\ -\ Isolated.tex 
pdflatex [path to your chapter folder]/[chapter]\ -\ Isolated.tex 
```

This will allow you to create a separate pdf file for your chapter. The files need to be compiled from within the main folder of the book, so that the paths to the figures work.

10. Add all your packages to the main.tex at the root folder of the book, if they are not already included there.

11. Compile the book following the instructions below from the main folder of the book. This will allow you to check whether your chapter is successfully included in the book.

```
pdflatex main.tex
pdflatex main.tex
```
