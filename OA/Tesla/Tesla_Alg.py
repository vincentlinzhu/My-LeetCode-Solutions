sample_input = [ 
    { 
        "name": "meas_1", 
        "type": "M", 
        "value": 1 
    }, 
    { 
        "name": "meas_2", 
        "type": "C", 
        "value": "meas_1", 
        "operation": "+" 
    }, 
    { 
        "name": "meas_2", 
        "type": "C", 
        "value": "meas_3", 
        "operation": "+" 
    }, 
    { 

        "name": "meas_3", 
        "type": "M", 
        "value": 4
    }, 
] 

def caculate_measurements(measurement_list): 
  # does not have to be in order
  # input is valid 
  # only M and C 
  # output should be dict
  
  type_m_c = defaultDict(list)
  type_c = defaultDict(list)
  result = {}

  # construct two dictionaries 
  for measurement in measurement_list:
    if measurement["type"] == "C":
      type_c[measurement["name"]].append(measurement["value"])
    type_m_c[measurement["name"]].append(measurement["value"])
    
  for name, values in type_m_c.items():
    # M type
    if values[0].isnumeric(): 
      result[name] = value
    # C type 
    else:
      total_value = 0
      for value in values:
        if type_m_c[value][0].isnumeric():
          total_value += type_m_c[value][0]
        else:
          newvalue = 
          while not type_m_c[newvalue][0].isnumeric():
            newname = type 
            newvalue = newname
          
    result[name] = total_value
    

  return result
    