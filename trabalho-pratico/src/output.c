#include "output.h"
#include <string.h>
#include <glib.h>
#include "queries.h"
#include "query_services.h"

void create_output_file(char *output_filename) {

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
      perror("Error creating output_file!");
      exit(1);
    }

    fclose(output_file);
}

FILE *create_output_query_file(int queries_counter) {
  char *filename = malloc(sizeof(char) * 256);
  sprintf(filename, "Resultados/command%d_output.txt", queries_counter);

  FILE *output_file = fopen(filename, "w");
  free(filename);

  return output_file;
}

void write_output_file(char** tokens,FILE* output_file, int max_tokens) {
    if (output_file == NULL) {
      perror("Error opening output_file!");
      exit(1);
    }
    int i = 0;
    while (i < max_tokens) {
      if (i == 0 && tokens[i] != NULL) {
        fprintf(output_file, "%s", tokens[i]);
      }
      else if (i == 0 && tokens[i] == NULL) {
      }
      else if (tokens[i] == NULL)
        fprintf(output_file,";");
      else
        fprintf(output_file, ";%s", tokens[i]);
      i++;
    }
    fprintf(output_file,"\n");
}

void write_output_queries_file(void* result, int query, FILE* output_file) {
    switch (query)
    {
    case 1:
      write_query1_results(result, output_file);
      break;
    case 2:
      write_query2_results(result, output_file);
      break;
    case 3:
      write_query3_results(result, output_file);
      break;
    case 4:
      write_query4_results(result, output_file);
      break;
    case 5:
      write_query5_results(result, output_file);
      break;
    case 6:
      write_query6_results(result, output_file);
      break;
    case 7:
      write_query7_results(result, output_file);
      break;
    case 8:
      write_query8_results(result, output_file);
      break;
    case 9:
      write_query9_results(result, output_file);
      break;
    case 10:
      write_query10_results(result, output_file);
      break;
    default:
      break;
    }
}

void write_query1_results(void* result, FILE* output_file) {
    Q1_results* info = (Q1_results*)result;

    if (info) {

        int type = get_q1_type(info);
        int flag = get_q1_flag(info);
        User* user;
        Flight* flight;
        Reservation* reservation;

        switch (type) {

        case 0: {
            user = get_q1_user(info);
            if (user) { 

              char* sex = get_user_sex(user);
              char* name = get_user_name(user);
              char* country_code = get_user_country_code(user);
              char* passport = get_user_passport(user);

              int age = calculate_age(get_user_birth_date(user));
              int num_flights = get_user_number_of_flights(user);
              int num_reservations = get_user_number_of_reservations(user);
              double total = get_user_total_spent(user);

              if (!flag)
                  fprintf(output_file, "%s;%s;%d;%s;%s;%d;%d;%.3f\n", name, sex, age, country_code, passport, num_flights, num_reservations, total);
              else
                  fprintf(output_file, "--- 1 ---\nname: %s\nsex: %s\nage: %d\ncountry_code: %s\npassport: %s\nnumber_of_flights: %d\nnumber_of_reservations: %d\ntotal_spent: %.3f\n",
                          name, sex, age, country_code, passport, num_flights, num_reservations, total);

              free(name);
              free(sex);
              free(country_code);
              free(passport);
            }
            break;
        }
        case 1:
            flight = get_q1_flight(info);
            if (info) {

              char* end_date = makeDate(get_flight_schedule_arrival_date(flight));
              char* begin_date = makeDate(get_flight_schedule_departure_date(flight));
              char* airline = get_flight_airline(flight);
              char* plane_model = get_flight_planemodel(flight);
              char* origin =  get_flight_origin(flight);
              char* dest = get_flight_destination(flight);

              if (!flag)

                  fprintf(output_file,"%s;%s;%s;%s;%s;%s;%d;%d\n", airline,plane_model, origin, 
                  dest, begin_date, end_date,
                  get_flight_totalseats(flight), get_flight_delay(flight));

              else 

                  fprintf(output_file,"--- 1 ---\nairline: %s\nplane_model: %s\norigin: %s\ndestination: %s\nschedule_departure_date: %s\nschedule_arrival_date: %s\npassengers: %d\ndelay: %d\n", 
                  airline,plane_model, origin, 
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

            if (reservation) {

                int hotel_id =get_hotel_id(reservation);
                char* hotel_name =get_hotel_name(reservation);
                char* end_date = makeDateRes(get_end_date(reservation));
                char* begin_date = makeDateRes(get_begin_date(reservation));
                int breakfast = get_breakfast(reservation);
                char* res_breackfast;

                if (breakfast==1) 
                    res_breackfast = "True";
                else res_breackfast = "False";
                if (!flag)
                    fprintf(output_file,"HTL%d;%s;%d;%s;%s;%s;%d;%.3f\n", hotel_id, hotel_name, get_hotel_stars(reservation), begin_date,
                    end_date,res_breackfast, num_nights, total);
                else 
                    fprintf(output_file,"--- 1 ---\nhotel_id: HTL%d\nhotel_name: %s\nhotel_stars: %d\nbegin_date: %s\nend_date: %s\nincludes_breakfast: %s\nnights: %d\ntotal_price: %.3f\n", 
                    hotel_id, hotel_name, get_hotel_stars(reservation), begin_date,
                    end_date,res_breackfast, num_nights, total);

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


void write_query2_results(void* result,FILE* output_file) {
    Q2_results* info = (Q2_results*)result;
    int count = get_q2_count(info);
    int flag = get_q2_flag(info);
    int datatype = get_q2_datatype(info);

    for (int i = 0; i < count; i++) {
      Date* date = get_q2_date(info,i);
      char* data = makeDateOnlyDate(date);
      int id = get_q2_id(info,i);
      int type = get_q2_type(info,i);

      if (type == 1) {
        if (!flag)
          if (datatype)
            fprintf(output_file,"%010d;%s;flight\n", id,data);
          else
            fprintf(output_file,"%010d;%s\n", id,data);
        else {
            if (i == count -1)
              if (datatype)
                fprintf(output_file,"--- %d ---\nid: %010d\ndate: %s\ntype: flight\n", i+1, id, data);
              else
                fprintf(output_file,"--- %d ---\nid: %010d\ndate: %s\n", i+1, id, data);
            else
              if (datatype)
                fprintf(output_file,"--- %d ---\nid: %010d\ndate: %s\ntype: flight\n\n", i+1, id, data);
              else
                fprintf(output_file,"--- %d ---\nid: %010d\ndate: %s\n\n", i+1, id, data);
        }
      }
      else {
        if (!flag)
          if (datatype)
            fprintf(output_file,"Book%010d;%s;reservation\n", id,data);
          else
            fprintf(output_file,"Book%010d;%s\n", id,data);
        else {  
            if (i == count -1)
              if (datatype)
                fprintf(output_file,"--- %d ---\nid: Book%010d\ndate: %s\ntype: reservation\n", i+1, id, data);
              else
                fprintf(output_file,"--- %d ---\nid: Book%010d\ndate: %s\n", i+1, id, data);
            else
              if (datatype)
                fprintf(output_file,"--- %d ---\nid: Book%010d\ndate: %s\ntype: reservation\n\n", i+1, id, data);
              else
                fprintf(output_file,"--- %d ---\nid: Book%010d\ndate: %s\n\n", i+1, id, data);
        }
        free(date);
      }

      free(data);

    }
    freeInfos2(info);
    free(info);
}


void write_query3_results(void* result,FILE* output_file) {
    Q3_results* info = (Q3_results*)result;
    double median = get_q3_median(info);
    int flag = get_q3_flag(info);

    if (!flag) {
      fprintf(output_file,"%.3f\n", median);
    }
    else
      fprintf(output_file,"--- 1 ---\nrating: %.3f\n", median);

    free(info);
}

void write_query4_results(void* result,FILE* output_file) {
    Q4_results* info = (Q4_results*)result;
    int flag = get_q4_flag(info);

    if (flag) {

      int count =  get_q4_count(info);
      for (int i = 0; i < count; i++) {

        int res_id = get_q4_reservation_id(info, i);
        char* user_id = get_q4_user_id(info,i);
        int rating = get_q4_rating(info, i);
        char* begin = get_q4_begin_date(info, i);
        char* end = get_q4_end_date(info, i);
        double total = get_q4_total_price(info,i);

        if (i == count-1)
          fprintf(output_file,"--- %d ---\nid: Book%010d\nbegin_date: %s\nend_date: %s\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n", i+1,res_id,begin,end,user_id,rating,total);
        else 
          fprintf(output_file,"--- %d ---\nid: Book%010d\nbegin_date: %s\nend_date: %s\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n\n", i+1,res_id,begin,end,user_id,rating,total);
        
        free(user_id);
        free(begin);
        free(end);
      }
    }
    else {
      int count =  get_q4_count(info);
      for (int i = 0; i < count; i++) {

        int res_id = get_q4_reservation_id(info, i);
        char* user_id = get_q4_user_id(info,i);
        int rating = get_q4_rating(info, i);
        char* begin = get_q4_begin_date(info, i);
        char* end = get_q4_end_date(info, i);
        double total = get_q4_total_price(info,i);

        
        fprintf(output_file,"Book%010d;%s;%s;%s;%d;%.3f\n",res_id,begin,end,user_id,rating,total);

        free(user_id);
        free(begin);
        free(end);
      }
    }
    free_q4infos(info);
    free(info);
}


void write_query5_results(void* result,FILE* output_file) {
  Q5_results* info = (Q5_results*)result;
  int flag = get_q5_flag(info);
  int num_flights = get_q5_count(info);

  for (int i = 0; i < num_flights; i++) {

    char* dep = get_q5_dep_date(info,i);
    int flight_id = get_q5_flight_id(info,i);
    char* dest = get_q5_destination(info,i);
    char* planemodel = get_q5_planemodel(info,i);
    char* airline = get_q5_airline(info,i);

    if (!flag) {
      fprintf(output_file,"%010d;%s;%s;%s;%s\n",flight_id,dep,dest,airline,planemodel);
    }
    else {
      if (i == num_flights -1)
        fprintf(output_file,"--- %d ---\nid: %010d\nschedule_departure_date: %s\ndestination: %s\nairline: %s\nplane_model: %s\n",i+1,flight_id,dep,dest,airline,planemodel);
      else
        fprintf(output_file,"--- %d ---\nid: %010d\nschedule_departure_date: %s\ndestination: %s\nairline: %s\nplane_model: %s\n\n",i+1,flight_id,dep,dest,airline,planemodel);
    }
    
    free(airline);
    free(dest);
    free(planemodel);
    free(dep);
  }
  free_q5_info(info);
  free(info);

}


void write_query6_results(void* result,FILE* output_file) {
  Q6_results* info = (Q6_results*)result;
  int flag =get_q6_flag(info);
  int count = get_q6_count(info);

  for (int i = 0; i < count; i++) {
    char* id = get_q6_id(info,i);

    if (!flag) {
      fprintf(output_file,"%s;%d\n",id,get_q6_num_passengers(info,i));
    }
    else {
      if (i == count -1)
        fprintf(output_file,"--- %d ---\nname: %s\npassengers: %d\n",i+1,id,get_q6_num_passengers(info,i));
      else
        fprintf(output_file,"--- %d ---\nname: %s\npassengers: %d\n\n",i+1,id,get_q6_num_passengers(info,i));
    }
    free(id);
  }

  free_q6_info(info);
  free(info);

}






void write_query7_results(void* result,FILE* output_file) {
    Q7_results* info = (Q7_results*)result;
    int num_infos = get_q7_num_infos(info);
    int flag = get_q7_flag(info);

    for (int i = 0; i < num_infos; i++) {
      char* airline =get_q7_name(info,i);

      if (flag) {
        if (i == num_infos-1) {
          fprintf(output_file, "--- %d ---\nname: %s\nmedian: %d\n", i+1,airline, get_q7_median(info,i));
        }
        else {
          fprintf(output_file, "--- %d ---\nname: %s\nmedian: %d\n\n", i+1,airline, get_q7_median(info,i));
        }
      }
      else {
        fprintf(output_file, "%s;%d\n", airline, get_q7_median(info,i));
      }
      free(airline);
    }
    free_q7infos(info);
    free(info);
}

void write_query8_results(void* result,FILE* output_file){
  Q8_results* info = (Q8_results*)result;
  int flag = get_q8_flag(info);
  int revenue = get_q8_result(info);
  
  if (flag) {
          fprintf(output_file, "--- 1 ---\nrevenue: %d\n", revenue);
      }
  else {
        fprintf(output_file, "%d\n", revenue);
  }

  free(info);
}


void write_query9_results(void* result,FILE* output_file) {
  Q9_results* info = (Q9_results*)result;
  int count = get_q9_num_infos(info);
  int flag = get_q9_flag(info);


  for (int i = 0; i < count; i++) {
      char* user_id = get_q9_user_id_info(info,i);
      char* user_name = get_q9_user_name_info(info,i);
      
      if (!flag) {
          fprintf(output_file, "%s;%s\n", user_id,user_name);
      }
      else {
        if (i == count -1) {
          fprintf(output_file, "--- %d ---\nid: %s\nname: %s\n",i+1, user_id,user_name);
        }
        else {
          fprintf(output_file, "--- %d ---\nid: %s\nname: %s\n\n", i+1, user_id,user_name);
        }
      }
      free(user_id);
      free(user_name);
  }

  free_q9_info(info);
  free(info);

}


void write_query10_results(void* result,FILE* output_file) {
  Q10_results* info = (Q10_results*)result;
  int flag = get_query10_flag(info); 
  int num_infos = get_query10_num_infos(info);
  int type = get_query10_type(info);

  char* date;
  switch (type)
  {
  case 0:
    date = "year";
    break;
  case 1:
    date = "month";
    break;
  case 2:
    date = "day";
    break;
  default:
    break;
  }

  for (int i = 0; i < num_infos; i++) {
    if (!flag) {
      fprintf(output_file,"%d;%d;%d;%d;%d;%d\n",get_q10_id(info,i),get_q10_num_users(info,i),get_q10_num_flights(info,i),get_q10_num_passengers(info,i),get_q10_num_single_passengers(info,i),get_q10_num_reservations(info,i));
    }
    else {
        if (i == num_infos-1) {
          fprintf(output_file, "--- %d ---\n%s: %d\nusers: %d\nflights: %d\npassengers: %d\nunique_passengers: %d\nreservations: %d\n",
          i+1,date,get_q10_id(info,i),get_q10_num_users(info,i),get_q10_num_flights(info,i),get_q10_num_passengers(info,i),get_q10_num_single_passengers(info,i),get_q10_num_reservations(info,i));
        }
        else {
          fprintf(output_file, "--- %d ---\n%s: %d\nusers: %d\nflights: %d\npassengers: %d\nunique_passengers: %d\nreservations: %d\n\n",
          i+1,date,get_q10_id(info,i),get_q10_num_users(info,i),get_q10_num_flights(info,i),get_q10_num_passengers(info,i),get_q10_num_single_passengers(info,i),get_q10_num_reservations(info,i));
        }
    }
  }
  free_q10infos(info);
  free(info);

}



char *create_filename(char *folder, const char *string) {
  char *filename = malloc(sizeof(char) * (strlen(folder) + strlen(string) + 1));
  strcpy(filename, folder);
  strcat(filename, string);
  return filename;
}


