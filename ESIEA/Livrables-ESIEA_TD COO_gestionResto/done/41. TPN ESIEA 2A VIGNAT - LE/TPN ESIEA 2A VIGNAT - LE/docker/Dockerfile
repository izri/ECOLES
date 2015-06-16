FROM debian:wheezy

RUN apt-get update && apt-get install php5-gd php5-intl php5-cli php5-mcrypt php5-mysql php5 apache2 git curl ca-certificates -y

RUN curl -sS https://getcomposer.org/installer | php
RUN mv composer.phar /usr/local/bin/composer

WORKDIR /var/www
RUN git clone https://git.p1rox.fr/ESIEA/WebResto.git webresto

WORKDIR /var/www/webresto
RUN composer install
RUN rm -rf export.sh docker README.md .env.example

WORKDIR /var/www
RUN chown -R www-data:www-data webresto/ && chmod -R 755 webresto/

WORKDIR /var/www/webresto

ADD env /var/www/webresto/.env
ADD vhost.conf /etc/apache2/sites-enabled/000-default

RUN a2enmod php5
RUN a2enmod rewrite

EXPOSE 80

CMD cd /var/www/webresto; php artisan migrate --force; /usr/sbin/apache2ctl -D FOREGROUND
