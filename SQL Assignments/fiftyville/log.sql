-- Keep a log of any SQL queries you execute as you solve the mystery.

-- getting description of crimes that took place on 28th July, Humphrey Street
SELECT id, description
    FROM crime_scene_reports
    WHERE (month = 7 AND day = 28 AND year = 2021 AND street = 'Humphrey Street');

-- reading transcripts of the three interviewees
SELECT name, transcript
    FROM interviews
    WHERE (year = 2021 AND day = 28 AND month = 7 AND transcript LIKE '%bakery%');

--following up on Ruth's testimony
SELECT license_plate
    FROM bakery_security_logs
    WHERE (month = 7 AND day = 28 AND year = 2021 AND hour = 10 AND minute BETWEEN 15 AND 25);


--following up on Eugene's testimony
SELECT id, account_number, transaction_type, amount
    FROM atm_transactions
    WHERE (year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street');

--following up on Raymond's testimony
SELECT id, caller, receiver
    FROM phone_calls
    WHERE (year = 2021 AND day = 28 AND month = 7 AND DURATION BETWEEN 0 AND 60);

-- flight follow up
SELECT flights.id
    FROM flights
        LEFT JOIN airports
        ON flights.origin_airport_id = airports.id
    WHERE (flights.month = 7 AND flights.day = 29 AND flights.year = 2021 AND airports.city = 'Fiftyville')
    ORDER BY flights.hour ASC, flights.minute ASC
    LIMIT 1;

    -- id = 36
    -- going to LaGuardia Airport

-- finding thief + their phone number - (367) 555-5533
SELECT people.name, people.phone_number
    FROM people
        LEFT JOIN bakery_security_logs
        ON people.license_plate = bakery_security_logs.license_plate
        LEFT JOIN passengers
        ON people.passport_number = passengers.passport_number
        LEFT JOIN phone_calls
        ON people.phone_number = phone_calls.caller
        LEFT JOIN bank_accounts
        ON people.id = bank_accounts.person_id
        LEFT JOIN atm_transactions
        ON bank_accounts.account_number = atm_transactions.account_number
            WHERE (bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.year = 2021 AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute BETWEEN 15 AND 25) AND
            (phone_calls.year = 2021 AND phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.duration BETWEEN 0 AND 60) AND
            passengers.flight_id = 36 AND
            (atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = 'withdraw');

-- finding accomplice
SELECT people.name
    FROM people
    LEFT JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
        WHERE phone_calls.caller = '(367) 555-5533' AND phone_calls.year = 2021 AND phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.DURATION BETWEEN 0 AND 60;

-- finding city
SELECT flights.id, airports.city
    FROM flights
        LEFT JOIN airports
        ON flights.destination_airport_id = airports.id
    WHERE flights.id = 36;
