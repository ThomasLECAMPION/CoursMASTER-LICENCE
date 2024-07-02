Exercice 1: Transformations dans le "clipping space" et "window space"

2.
P3(0.2994, 0.1104)
P7(0.386, 0.0667)

3.
Les transformations nécessaires sont:
-Les transformations de modélisation

4.
Les transformations nécessaires sont:
-Les transformations de l’objet

5.
Les transformations nécessaires sont:
-Les transformations de l’objet

Pour modéliser le flocon des trois viewports j'ai utilisé la méthode drawArrayInstanced, ce qui m'a permit de dupliquer le motif de base et de l'orienter selon son ID dans le vertex shader grâce à des matrices de rotations.
Les modifications spécifiques à un viewport sont paramétrées dans l'appel de la scène. On y entre un flottant pour le scaling de l'objet, puis trois flottants qui ordonne une rotation sur l'axe correspondant.
Nous envoyons ces paramètres au vertex shader par des uniforms.
