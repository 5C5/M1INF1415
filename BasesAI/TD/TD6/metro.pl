ligne(a, [perrache, ampere, bellecour, cordeliers, hotel_de_ville, foch, massena, charpennes, republique, gratte_ciel, flachet, cusset, laurent_bonnevay, vaulx_en_velin]).
ligne(b, [charpennes, brotteaux, part_dieu, place_guichard, saxe_gambetta, jean_mace, place_jean_jaures, debourg, stade_de_gerland, oullins_gare]).
ligne(c, [hotel_de_ville, croix_paquet, croix_rousse, henon, cuire]).
ligne(d, [gare_de_vaise, valmy, gorge_de_loup, vieux_lyon, bellecour, guillotiere, saxe_gambetta, garibaldi, sans_souci, montplaisir, grange_blanche, lannec, mermoz_pinnel, parilly, gare_de_venissieux]).


appartient(X, [X|_]).
appartient(X, [_|L]):- appartient(X, L).

est_sur(S, L) :- ligne(L, Q), appartient(S, Q).

cherche_ligne(S, L):-
	est_sur(S, L).


parcours(X, X, _, _).
parcours(X, Y, ).

chemin(D, A) :- parcours(D, A, [], Chm), affichage(Chm).
