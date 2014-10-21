# TP Sparql
Colas PICARD

## Questions
1. <http://rdf.freebase.com/key/>
2.
		PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>
		PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema#>
		PREFIX film: <http://rdf.freebase.com/ns/m.0fp_fq_#>

		SELECT ?n WHERE {
			  ?n film:label ?e.
		} LIMIT 10
3. 
