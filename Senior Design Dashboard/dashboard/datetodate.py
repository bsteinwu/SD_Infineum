def datetodate(date):
    date_list = date.split('/')
    if len(date_list[0]) == 1:
        date_list[0] = '0' + date_list[0]

    if len(date_list[1]) == 1:
        date_list[1] = '0' + date_list[1]

    if len(date_list[2]) == 2:
        date_list[2] = '20' + date_list[2]

    final_date = date_list[2] + '-' + date_list[0] + '-' + date_list[1] + ' 00:00:00'
    return final_date