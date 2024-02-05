#include "draw_outputs.h"
#include "queries.h"
#include "query_services.h"

void draw_query1_results(void *result, WINDOW *win)
{
    Q1_results *info = (Q1_results *)result;

    if (info)
    {
        int type = get_q1_type(info);
        User *user;
        Flight *flight;
        Reservation *reservation;
        switch (type)
        {
        case 0:
        {
            user = get_q1_user(info);
            if (user)
            {
                char *sex = get_user_sex(user);
                char *name = get_user_name(user);
                int age = calculate_age(get_user_birth_date(user));
                char *country_code = get_user_country_code(user);
                char *passport = get_user_passport(user);
                int num_flights = get_user_number_of_flights(user);
                int num_reservations = get_user_number_of_reservations(user);
                double total = get_user_total_spent(user);

                mvwprintw(win, 2, 4, "%s;%s;%d;%s;%s;%d;%d;%.3f", name, sex, age, country_code, passport, num_flights, num_reservations, total);

                // Liberar memória alocada
                free(name);
                free(sex);
                free(country_code);
                free(passport);
            }
            break;
        }
        case 1:
            flight = get_q1_flight(info);
            if (info)
            {
                char *end_date = makeDate(get_flight_schedule_arrival_date(flight));
                char *begin_date = makeDate(get_flight_schedule_departure_date(flight));
                char *airline = get_flight_airline(flight);
                char *plane_model = get_flight_planemodel(flight);
                char *origin = get_flight_origin(flight);
                char *dest = get_flight_destination(flight);
                mvwprintw(win, 2, 4, "%s;%s;%s;%s;%s;%s;%d;%d", airline, plane_model, origin,
                          dest, begin_date, end_date,
                          get_flight_totalseats(flight), get_flight_delay(flight));
                free(begin_date);
                free(end_date);
                free(airline);
                free(plane_model);
                free(origin);
                free(dest);
            }
            break;
        case 2:
            reservation = get_q1_reservation(info);
            int num_nights = calculate_day(get_begin_date(reservation), get_end_date(reservation));
            double total = total_spent(reservation);
            if (reservation)
            {
                char *end_date = makeDateRes(get_end_date(reservation));
                char *begin_date = makeDateRes(get_begin_date(reservation));
                int breakfast = get_breakfast(reservation);
                int hotel_id =get_hotel_id(reservation);
                char *hotel_name = get_hotel_name(reservation);

                char *res_breackfast;
                if (breakfast==1)
                    res_breackfast = "True";
                else
                    res_breackfast = "False";
                mvwprintw(win, 2, 4, "%d;%s;%d;%s;%s;%s;%d;%.3f", hotel_id, hotel_name, get_hotel_stars(reservation), begin_date,
                          end_date, res_breackfast, num_nights, total);

                free(begin_date);
                free(end_date);
                free(hotel_name);
            }
            break;
        default:
            break;
        }
    }
    free(info);
}

void draw_query2_results(void *result, WINDOW *win)
{
    int y, x;
    getmaxyx(win, y, x);

    Q2_results *info = (Q2_results *)result;
    if (info == NULL)
        return;
    int count = get_q2_count(info);

    int current_page = 0;
    int elements_per_page = y - 4;
    int max_pages = (int)(count / elements_per_page) + 1;

    int ch;
    while (1)
    {

        int counter = 0;
        int start = current_page * elements_per_page;
        int end = start + elements_per_page - 1;

        for (int i = start; i <= end && i < count; i++)
        {
            Date *date = get_q2_date(info, i);
            char *data = makeDateOnlyDate(date);
            int id = get_q2_id(info, i);
            int type = get_q2_type(info, i);

            mvwprintw(win, 2 + counter, 4, "%010d;%s;%s", id, data, (type == 1) ? "flight" : "reservation");

            free(data);
            free(date);
            counter++;
        }

        mvwprintw(win, y - 2, x/6, " Page %d of %d ", current_page + 1, max_pages);
        mvwprintw(win, y - 1, x/6, " Press double 'q' to quit, 'n' for next page, 'p' for previous page ");

        ch = wgetch(win);

        // Lidar com a entrada do usuário
        switch (ch)
        {
        case 'q':
            freeInfos2(info);
            free(info);
            return;
            break; // Sair do loop
        case 'n':
            current_page = (current_page + 1) % max_pages;
            break;
        case 'p':
            current_page = (current_page - 1 + max_pages) % max_pages;
            break;
        default:
            break;
        }

        wrefresh(win);

        // Exibir informações de paginação

        if (ch == 'q')
        {
            break;
        }
    }
}

void draw_query3_results(void *result, WINDOW *win)
{
    Q3_results *info = (Q3_results *)result;
    if (result == NULL)
        return;
    double median = get_q3_median(info);

    mvwprintw(win, 2, 4, "%.3f", median);

    free(info);
}

void draw_query4_results(void *result, WINDOW *win)
{
    int y, x;
    getmaxyx(win, y, x);
    Q4_results *info = (Q4_results *)result;
    if (result == NULL)
        return;

    int count = get_q4_count(info);
    int items_per_page = y - 4; // Número de itens por página (altura da janela - margens)
    int max_pages = (int)(count / items_per_page) + 1;

    int current_page = 0;
    int ch;

    while (1)
    {
        wclear(win);
        box(win, 0, 0);

        int start = current_page * items_per_page;
        int end = (start + items_per_page - 1 < count - 1) ? start + items_per_page - 1 : count - 1;

        for (int i = start; i <= end; i++)
        {
            int res_id = get_q4_reservation_id(info, i);
            char *user_id = get_q4_user_id(info, i);
            int rating = get_q4_rating(info, i);
            char *begin = get_q4_begin_date(info, i);
            char *end_date = get_q4_end_date(info, i);
            double total = get_q4_total_price(info, i);

            mvwprintw(win, i - start + 1, 2, "Book%010d;%s;%s;%s;%d;%.3f", res_id, begin, end_date, user_id, rating, total);

            free(begin);
            free(end_date);
        }

        // Exibir informações de paginação
        mvwprintw(win, y - 2, x/6, "Page %d of %d", current_page + 1, max_pages);
        mvwprintw(win, y - 1, x/6, "Press double 'q' to quit, 'n' for next page, 'p' for previous page");
        refresh();
        wrefresh(win);

        // Aguarde a entrada do usuário
        ch = getch();

        // Lidar com a entrada do usuário
        switch (ch)
        {
        case 'q':
            break; // Sair do loop
        case 'n':
            if (end < count - 1)
            {
                current_page++;
            }
            break;
        case 'p':
            if (current_page > 0)
            {
                current_page--;
            }
            break;
        default:
            break;
        }

        if (ch == 'q')
        {
            break;
        }
    }
    // Liberar memória alocada
    free_q4infos(info);
    free(info);
}

void draw_query5_results(void *result, WINDOW *win)
{
    int y, x;
    getmaxyx(win, y, x);
    Q5_results *info = (Q5_results *)result;
    if (result == NULL)
        return;
    int num_flights = get_q5_count(info);

    int current_page = 0;
    int items_per_page = y - 4; // Número de itens por página (altura da janela - margens)
    int max_pages = (int)(num_flights / items_per_page) + 1;

    int ch;

    while (1)
    {
        wclear(win);
        box(win, 0, 0);

        int start = current_page * items_per_page;
        int end = (start + items_per_page - 1 < num_flights - 1) ? start + items_per_page - 1 : num_flights - 1;

        for (int i = start; i <= end; i++)
        {
            char *dep = get_q5_dep_date(info, i);
            int flight_id = get_q5_flight_id(info, i);
            char *dest = get_q5_destination(info, i);
            char *planemodel = get_q5_planemodel(info, i);
            char *airline = get_q5_airline(info, i);

            mvwprintw(win, i - start + 1, 2, "%010d;%s;%s;%s;%s", flight_id, dep, dest, airline, planemodel);

            free(dest);
            free(planemodel);
            free(airline);
            free(dep);
        }

        // Exibir informações de paginação
        mvwprintw(win, y - 2, x/6, "Page %d of %d", current_page + 1, max_pages);
        mvwprintw(win, y - 1, x/6, "Press 'q' to quit, 'n' for next page, 'p' for previous page");
        refresh();
        wrefresh(win);

        // Aguarde a entrada do usuário
        ch = getch();

        // Lidar com a entrada do usuário
        switch (ch)
        {
        case 'q':
            break; // Sair do loop
        case 'n':
            if (end < num_flights - 1)
            {
                current_page++;
            }
            break;
        case 'p':
            if (current_page > 0)
            {
                current_page--;
            }
            break;
        default:
            break;
        }

        if (ch == 'q')
        {
            break;
        }
    }

    // Liberar memória alocada
    free_q5_info(info);
    free(info);
}

void draw_query6_results(void *result, WINDOW *win)
{
    int y, x;
    getmaxyx(win, y, x);
    Q6_results *info = (Q6_results *)result;
    if (result == NULL)
        return;
    int count = get_q6_count(info);

    int current_page = 0;
    int items_per_page = y - 4; // Número de itens por página (altura da janela - margens)
    int max_pages = (int)(count / items_per_page) + 1;

    int ch;

    while (1)
    {
        wclear(win);
        box(win, 0, 0);

        int start = current_page * items_per_page;
        int end = (start + items_per_page - 1 < count - 1) ? start + items_per_page - 1 : count - 1;

        for (int i = start; i <= end; i++)
        {
            char* id = get_q6_id(info, i);
            mvwprintw(win, i - start + 1, 2, "%s;%d", id, get_q6_num_passengers(info, i));
            free(id);
        }

        // Exibir informações de paginação
        mvwprintw(win, y - 2, x/6, "Page %d of %d", current_page + 1, max_pages);
        mvwprintw(win, y - 1, x/6, "Press double 'q' to quit, 'n' for next page, 'p' for previous page");
        refresh();
        wrefresh(win);

        // Aguarde a entrada do usuário
        ch = getch();

        // Lidar com a entrada do usuário
        switch (ch)
        {
        case 'q':
            break; // Sair do loop
        case 'n':
            if (end < count - 1)
            {
                current_page++;
            }
            break;
        case 'p':
            if (current_page > 0)
            {
                current_page--;
            }
            break;
        default:
            break;
        }

        if (ch == 'q')
        {
            break;
        }
    }

    // Liberar memória alocada
    free_q6_info(info);
    free(info);
}

void draw_query7_results(void *result, WINDOW *win)
{
    int y, x;
    getmaxyx(win, y, x);
    Q7_results *info = (Q7_results *)result;
    if (result == NULL)
        return;
    int num_infos = get_q7_num_infos(info);

    int current_page = 0;
    int items_per_page = y - 4; // Número de itens por página (altura da janela - margens)
    int max_pages = (int)(num_infos / items_per_page) + 1;

    int ch;

    while (1)
    {
        wclear(win);
        box(win, 0, 0);

        int start = current_page * items_per_page;
        int end = (start + items_per_page - 1 < num_infos - 1) ? start + items_per_page - 1 : num_infos - 1;

        for (int i = start; i <= end; i++)
        {
            char* name = get_q7_name(info, i);
            mvwprintw(win, i - start + 1, 2, "%s;%d", name, get_q7_median(info, i));
            free(name);
        }

        // Exibir informações de paginação
        mvwprintw(win, y - 2, x/6, "Page %d of %d", current_page + 1, max_pages);
        mvwprintw(win, y - 1, x/6, "Press double 'q' to quit, 'n' for next page, 'p' for previous page");
        refresh();
        wrefresh(win);

        // Aguarde a entrada do usuário
        ch = getch();

        // Lidar com a entrada do usuário
        switch (ch)
        {
        case 'q':
            break; // Sair do loop
        case 'n':
            if (end < num_infos - 1)
            {
                current_page++;
            }
            break;
        case 'p':
            if (current_page > 0)
            {
                current_page--;
            }
            break;
        default:
            break;
        }

        if (ch == 'q' || end >= num_infos - 1)
        {
            break;
        }
    }

    // Liberar memória alocada
    free_q7infos(info);
    free(info);
}

void draw_query8_results(void *result, WINDOW *win)
{
    Q8_results *info = (Q8_results *)result;
    if (result == NULL)
        return;
    int revenue = get_q8_result(info);

    mvwprintw(win, 2, 4, "%d", revenue);

    // Liberar memória alocada
    free(info);
}

void draw_query9_results(void *result, WINDOW *win)
{
    int y, x;
    getmaxyx(win, y, x);

    Q9_results *info = (Q9_results *)result;
    int count = get_q9_num_infos(info);

    int current_page = 0;
    int items_per_page = y - 4; // Número de itens por página (altura da janela - margens)
    int max_pages = (int)(count / items_per_page) + 1;

    int ch;
    while (1)
    {
        wclear(win);
        box(win, 0, 0);
        int start = current_page * items_per_page;
        int end = start + items_per_page - 1;
        if (end >= count)
        {
            end = count - 1;
        }

        for (int i = start; i <= end; i++)
        {
            char* user_id = get_q9_user_id_info(info, i);
            char* user_name = get_q9_user_name_info(info, i);
            mvwprintw(win, i - start + 1, 2, "%s;%s", user_id, user_name);
            free(user_id);
            free(user_name);
        }

        // Exibir informações de paginação
        mvwprintw(win, y - 2, x/6, "Page %d of %d", current_page + 1, max_pages);
        mvwprintw(win, y - 1, x/6, "Press double 'q' to quit, 'n' for next page, 'p' for previous page");
        refresh();
        wrefresh(win);
        // Aguarde a entrada do usuário
        ch = getch();

        // Lidar com a entrada do usuário
        switch (ch)
        {
        case 'q':
            break; // Sair do loop
        case 'n':
            if (end < count - 1)
            {
                current_page++;
            }
            break;
        case 'p':
            if (current_page > 0)
            {
                current_page--;
            }
            break;
        default:
            break;
        }

        if (ch == 'q')
        {
            break;
        }
    }
    // Liberar memória alocada
    free_q9_info(info);
    free(info);
}

void draw_query10_results(void *result, WINDOW *win)
{
    int y, x;
    getmaxyx(win, y, x);
    Q10_results *info = (Q10_results *)result;
    if (result == NULL) return;
    int num_infos = get_query10_num_infos(info);


    int current_page = 0;
    int items_per_page = y - 4; // Número de itens por página (altura da janela - margens)
    int max_pages = (int)(num_infos / items_per_page) + 1;

    int ch;

    while (1)
    {
        wclear(win);
        box(win,0,0);

        int start = current_page * items_per_page;
        int end = (start + items_per_page - 1 < num_infos - 1) ? start + items_per_page - 1 : num_infos - 1;

        for (int i = start; i <= end; i++)
        {
            mvwprintw(win, i - start + 1, 2, "%d;%d;%d;%d;%d;%d", get_q10_id(info, i), get_q10_num_users(info, i), get_q10_num_flights(info, i), get_q10_num_passengers(info, i), get_q10_num_single_passengers(info, i), get_q10_num_reservations(info, i));
        }

        // Exibir informações de paginação
        mvwprintw(win, y - 2, x/6, "Page %d of %d", current_page + 1, max_pages);
        mvwprintw(win, y - 1, x/6, "Press 'q' to quit, 'n' for next page, 'p' for previous page");
        refresh();
        wrefresh(win);

        // Aguarde a entrada do usuário
        ch = getch();

        // Lidar com a entrada do usuário
        switch (ch)
        {
        case 'q':
            break; // Sair do loop
        case 'n':
            if (end < num_infos - 1)
            {
                current_page++;
            }
            break;
        case 'p':
            if (current_page > 0)
            {
                current_page--;
            }
            break;
        default:
            break;
        }

        if (ch == 'q' || end >= num_infos - 1)
        {
            break;
        }
    }

    // Liberar memória alocada
    free_q10infos(info);
    free(info);
}