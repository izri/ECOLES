N = 100;     %Number of users
R = 10;     %Radius of Hexagon


%Generating a hexagon with centre (0,0)
    %Vertexes
    v_x = R * cos((0:6)*pi/3);
    v_y = R * sin((0:6)*pi/3);

    %Generate 3N random points with square that is 2R by 2R
    c_x = R-rand(1,3*N)*2*R;
    c_y = R-rand(1,3*N)*2*R;

    %get the points within the polygon
    IN = inpolygon(c_x, c_y, v_x, v_y);

    %drop nodes outside the hexagon
    c_x = c_x(IN);
    c_y = c_y(IN);
    plot(c_x, c_y, 'r*')
    grid on
    hold on
  


%choose only N points
idx = randperm(length(c_x));
c_x = c_x(idx(1:N));
c_y = c_y(idx(1:N));


plot(v_x,v_y)
axis square
hold off