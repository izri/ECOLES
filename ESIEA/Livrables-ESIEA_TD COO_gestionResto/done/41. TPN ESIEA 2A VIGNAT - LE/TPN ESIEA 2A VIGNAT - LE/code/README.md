# WebResto
### Projet d'informatique sur la POO.

## Installation :
### Requis:
- Apache de préférence (activer mod_rewrite et autoriser les .htaccess)
- PHP 5.5
- MySQL
- composer

### Guide
1. Cloner le dépôt.
2. Aller dans le dossier du projet.
3. Executer `composer install`.
4. Créer une base de données `WebResto` ainsi qu'un utilisateur avec les permissions sur cette base.
5. Executer `php artisan migrate` pour créer les tables dans la base de données.