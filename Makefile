article.pdf: article.tex
	latexmk -pdf $<
	latexmk -c $<
	
