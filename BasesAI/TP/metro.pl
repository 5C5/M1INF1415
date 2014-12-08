# Programme de parcours du metro Lyonnais
% Description des lignes

ligne(a,[perrache,ampere,bellecour,cordeliers,hotel_de_ville,foch,massena,charpennes,republique,gratte_ciel,flachet,cusset,laurent_bonnevay,vaulx_en_velin]).

ligne(b,[charpennes,brotteaux,part_dieu,place_guichard,saxe_gambetta,jean_mace,place_jean_jaures,debourg,stade_de_gerland,oullins_gare]).

ligne(c,[hotel_de_ville,croix-paquet,croix-rousse,henon,cuire]).

ligne(d,[gare_de_vaise,valmy,gorge_de_loup,vieux_lyon,bellecour,guillotiere,saxe_gambetta,garibaldi,sans_souci,monplaisir,grange_blanche,lannec,mermoz_pinel,parilly,gare_de_venissieux]).

%# Predicat permettant d'obtenir la ligne sur laquelle se trouve une station.
cherche_ligne(St, Ligne):- ligne(Ligne, List), member(St, List).

# Prédicats pour l'affichage d'un chemin
affichage(Prc):- display_liste(['Chemin :',nl|Prc]), nl.
display_liste([]).
display_liste([nl|R]):-nl, display_liste(R),!.
display_liste([X|R]):-display(X), display(' '), display_liste(R).

# Prédicat de recherche d un chemin.
chemin(A,B):- parcours(A,B,[],Chm), affichage(Chm).

# Prédicat de recherche de parcours
parcours(D, A, I, Chemin).
