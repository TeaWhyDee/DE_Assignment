#pragma once

#include "Exact.h"

GraphPoints Exact::get_points(float x0, float y0, float X, int N){
    function->update(x0, y0);
    const float len = X - x0;
    const float step = float(len) / float(N);
    printf("step: %f\n", step);

    std::vector<float> disc_pts = function->get_discontinuity_points();
    GraphPoints points;
    float x = x0;
    auto next_disc_pt = disc_pts.begin();
    printf("first disc pt: %f\n", *next_disc_pt);
    printf("disc_pts size: %d\n", disc_pts.size());
    while ( *next_disc_pt <= x0 && next_disc_pt != disc_pts.end() ){
        next_disc_pt++;
        printf("new disc pt: %f\n", *next_disc_pt);
    }
    points.graph_parts[points.size()-1].push_back( Point(x0, y0) );
    for (int i = 0; i < N; ++i){
        x += step;
        // Search for current x among upcoming discontinuity points.
        if(std::find(next_disc_pt, disc_pts.end(), x) != disc_pts.end()) {
            printf(" -on a discontinuity point- ");
            if ( points[points.size()-1].size() != 0 ){
                points.add_graph_part();
            }
            if ( next_disc_pt != disc_pts.end() ) {
                next_disc_pt++;
            }
            continue;
        }
        else if ( x > *next_disc_pt && next_disc_pt != disc_pts.end()){
            printf(" -passed a discontinuity point- ");
            while (x > *next_disc_pt && next_disc_pt != disc_pts.end()){
                next_disc_pt++;
                printf("next disc pt: %f\n", *next_disc_pt);
            }
            if ( points[points.size()-1].size() != 0 ){
                points.add_graph_part();
            }
        }
        float y = function->get_y_at_x(x);
        points.graph_parts[points.size()-1].push_back( Point(x, y) );
    }
    return points;
};

Exact::Exact( Function* func ){
    function = func;
}
