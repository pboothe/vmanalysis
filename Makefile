article.pdf: article.tex
	pdflatex article
	bibtex article
	latexmk -pdf $<
	latexmk -c $<
