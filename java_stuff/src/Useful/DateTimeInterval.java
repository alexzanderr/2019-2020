package Useful;

import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalTime;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Locale;

public class DateTimeInterval {
    private LocalDateTime start;
    private LocalDateTime stop;

    private DateTimeInterval(final LocalDateTime start, final LocalDateTime stop) {
        this.start = start;
        this.stop = stop;
    }

    public static DateTimeInterval Instantiate(final LocalDateTime start, final LocalDateTime stop) throws InstantiationException {
        if (start == null || stop == null) {
            throw new InstantiationException("<null parameters>");
        }
        if (start.compareTo(stop) >= 0) {
            throw new InstantiationException("<start date > stop date>");
        }
        return new DateTimeInterval(start, stop);
    }

    public static DateTimeInterval Instantiate(final LocalDateTime start, final Duration d) throws InstantiationException {
        if (d == null) {
            throw new InstantiationException("<duration is null>");
        }
        return Instantiate(start, start.plus(d));
    }

    public static DateTimeInterval Instantiate(final LocalDateTime start,
                                        final int days,
                                        final int hours,
                                        final int minutes,
                                        final int seconds)
            throws InstantiationException {
        return Instantiate(start, start.plusDays(days).plusHours(hours).plusMinutes(minutes).plusSeconds(seconds));
    }

    public static DateTimeInterval Instantiate(final LocalDate start_date,
                                        final LocalTime start_time,
                                        final LocalDate stop_date,
                                        final LocalTime stop_time) throws InstantiationException{
        return Instantiate(start_date.atTime(start_time), stop_date.atTime(stop_time));
    }

    public boolean Overlaps(DateTimeInterval dti) {
        return this.start.compareTo(dti.stop) <= 0 && this.stop.compareTo(dti.start) >= 0;
    }

    private String FormaterActivation(LocalDateTime ldt) {
        return ldt.format(DateTimeFormatter.ofPattern("EEEE dd.MM.yyyy HH:mm:ss",
                        new Locale("en", "USA")));
    }

    @Override
    public String toString() {
        String result = "";
        result += "Your DateTimeInterval is from: " + FormaterActivation(this.start) + " to " + FormaterActivation(this.stop);
        return result;
    }
}