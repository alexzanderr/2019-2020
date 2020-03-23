

def GetLocationFromAddress(physical_address):
    geolocator_url = "https://nominatim.openstreetmap.org/"
    search_parameters = "+".join(physical_address.split())
    search_parameters = f"search.php?q={search_parameters}"

    from andrew_packages.util.webscrapper import Scrappy
    from requests import get
    page = get(geolocator_url + search_parameters, headers=Scrappy.my_user_agent)

    htmlcode = page.text
    start_index = htmlcode.index('var nominatim_results = [')
    start_index += len('var nominatim_results = [') - 1
    search_results = ""
    while True:
        search_results += htmlcode[start_index]
        start_index += 1
        if htmlcode[start_index] == ";":
            break

    import json
    search_results = search_results.replace('null', 'None')
    search_results = eval(search_results)

    # this is a dictionary with information about this address
    return search_results

def VisualizeLocation(location_information):
    from selenium import webdriver
    from selenium.webdriver.common.keys import Keys
    from time import sleep

    googlemaps_url = 'https://www.google.com/maps'
    chromedriver_path = "D:\\chrome_driver\\version_80\\chromedriver.exe"
    chrome_driver = webdriver.Chrome(chromedriver_path)
    chrome_driver.maximize_window()
    chrome_driver.get(googlemaps_url)

    while True:
        try:
            searchbox = chrome_driver.find_element_by_xpath('//*[@id="searchboxinput"]')
            break
        except:
            pass

    geolocation_coordinates = f"{location_information[0]['lat']}, {location_information[0]['lon']}"

    while True:
        try:

            searchbox.send_keys(geolocation_coordinates)
            break
        except:
            pass

    while True:
        try:
            searchbutton = chrome_driver.find_element_by_xpath('//*[@id="searchbox-searchbutton"]')
            searchbutton.click()
            break
        except:
            pass
    sleep(1)

    # remaining locations with that address
    for location_dict in location_information[1:]:
        chrome_driver.execute_script("window.open('');")
        chrome_driver.switch_to.window(chrome_driver.window_handles[-1])
        chrome_driver.get(googlemaps_url)
        while True:
            try:
                searchbox = chrome_driver.find_element_by_xpath('//*[@id="searchboxinput"]')
                break
            except:
                pass

        geolocation_coordinates = f"{location_dict['lat']}, {location_dict['lon']}"

        while True:
            try:

                searchbox.send_keys(geolocation_coordinates)
                break
            except:
                pass

        while True:
            try:
                searchbutton = chrome_driver.find_element_by_xpath('//*[@id="searchbox-searchbutton"]')
                searchbutton.click()
                break
            except:
                pass
        sleep(1)
    input("waiting to close chrome driver")