<?php

$STR_END = "<br>";

interface StringOutputter {
    public function to_string();
}

class Subject implements StringOutputter {
    private ?string $m_name;

    function __construct(?string $name = null) {
        $this->set_name($name);
    }

    public function get_name() {
        return $this->m_name;
    }

    public function set_name(?string $name) {
        $this->m_name = $name;
    }

    public function to_string() {
        return $this->m_name;
    }
}

class DayOfWeekEnum {
    public const NULL = 0;
    public const MONDAY = 1;
    public const TUESDAY = 2;
    public const WEDNESDAY = 3;
    public const THURSDAY = 4;
    public const FRIDAY = 5;
    public const SATURDAY = 6;
    public const SUNDAY = 7;

    private ?int $m_day_of_week;

    public function __construct(?int $day_of_week = 0) {
        $this->m_day_of_week = $day_of_week;
    }

    public function __toInt() {
        return $this->m_day_of_week;
    }
}

class DayOfWeekConverter {
    public static function convert(?DayOfWeekEnum $day_of_week) {
        if (!is_null($day_of_week)) {
            static $week_map = array(
                    DayOfWeekEnum::MONDAY => "Понедельник",
                    DayOfWeekEnum::TUESDAY => "Вторник",
                    DayOfWeekEnum::WEDNESDAY => "Среда",
                    DayOfWeekEnum::THURSDAY => "Четверг",
                    DayOfWeekEnum::FRIDAY => "Пятница",
                    DayOfWeekEnum::SATURDAY => "Суббота",
                    DayOfWeekEnum::SUNDAY => "Воскресенье",
            );

            return $week_map[$day_of_week->__toInt()];
        }

        return "null";
    }
}

class DailySchedule implements StringOutputter {
    private ?array $m_subjects;    // array<Subject>;
    private ?DayOfWeekEnum $m_day_of_week;

    function __construct(?array $subjects = null) {
        if ($subjects === null) {
            $subjects = array();
        }
        $this->set_subjects($subjects);
        // $m_day_of_week = new DayOfWeekEnum();
    }

    public function get_subjects() {
        return $this->m_subjects;
    }

    public function set_subjects(?array $subjects) {
        $this->m_subjects = $subjects;
    }
    
    public function get_day_of_week() {
        return $this->m_day_of_week;
    }

    public function set_day_of_week(?DayOfWeekEnum $day_of_week) {
        $this->m_day_of_week = $day_of_week;
    }

    public function to_string() {
        global $STR_END;

        if (!is_null($this->m_day_of_week)) {
            $ret = DayOfWeekConverter::convert($this->m_day_of_week) . ":" . $STR_END;
        } else {
            $ret = "День недели неизвестен: $STR_END";
        }

        if (!is_null($this->m_subjects)) {
            $i = 1;
            foreach ($this->m_subjects as $subject) {
                $ret .= $i++ . ") " . $subject->to_string() . $STR_END;
            }
        }

        return $ret;
    }

    public function push_subject(?Subject $subject) {
        $this->m_subjects[] = $subject;
    }
}

function main() {
    global $STR_END;

    $LAST_WORK_DAY = DayOfWeekEnum::FRIDAY;
    $LESSONS_IN_DAY = 6;

    $all_subjects = [
        new Subject("математика"),
        new Subject("украинский"),
        new Subject("литература"),
        new Subject("физкультура"),
        new Subject("физика"),
        new Subject("химия"),
        new Subject("астрономия"),
        new Subject("биология"),
        new Subject("информатика"),
        new Subject("музыка"),
    ];
    
    $schedule = array();  // array<DailySchedule>;
    for ($i = DayOfWeekEnum::MONDAY; $i <= DayOfWeekEnum::SUNDAY; ++$i) {
        $daily_schedule = new DailySchedule();
        $daily_schedule->set_day_of_week(new DayOfWeekEnum($i));
        if ($i <= $LAST_WORK_DAY) {
            for ($lesson_num = 0; $lesson_num < $LESSONS_IN_DAY; ++$lesson_num) {
                $daily_schedule->push_subject($all_subjects[array_rand($all_subjects)]);
            }
        }

        array_push($schedule, $daily_schedule);
    }

    foreach ($schedule as $day) {
        echo $day->to_string() . "<br>";
    }
}

main();

?>